// 2021 Patricio Loncomilla

#ifndef IN_OPERATOR_H_
#define IN_OPERATOR_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <initializer_list>

// "a in b" can be used when:
// 1) "a" is a character and "b" is a string
// 2) "a" is a string and "b" is a string
// 3) "a" is an element and "b" is a vector
// 4) "a" is an element and "b" is a set
// 5) "a" is an element and "b" is a map

// For using the in operator, add these lines:
// #define in <in_operator::in>
// #define not_in <in_operator::not_in>


/*********
 Function L(), optional
**********/
namespace in_operator_L
{
template <class T>
const std::initializer_list<T> L(const std::initializer_list<T>& list) {return list;}
}

// In this case none of the overloads matched the types used

#if !defined(__GNUC__)
template <class T, class E>
inline bool contains__(const T& elem, const E& other)
{
  static_assert(false, "\"in\" operator used on invalid types (see file: in_operator.h)");
  return false;
}
#else
template <class T, class E>
inline bool contains__(const T& elem, const E& other) = delete;  // "in" operator used on invalid types (see file: in_operator.h)
#endif

/***************
 Overloads for vector
****************/
template <class T>
inline bool contains__(const std::vector<T>& vect, const T& elem)
{
  for (const T& it : vect)
  {
    if (it == elem)
      return true;
  }
  return false;
}

/********************************
 Overloads for initializer list
*********************************/
template <class T>
inline bool contains__(const std::initializer_list<T>& list, const T& elem)
{
  for (const T& it : list)
  {
    if (it == elem)
      return true;
  }
  return false;
}

/********************************
 Overloads for set
*********************************/

template <class T>
inline bool contains__(const std::set<T>& myset, const T& elem)
{
  return myset.find(elem) != myset.end();
}

/********************************
 Overloads for map
*********************************/

template <class T, class E>
inline bool contains__(const std::map<T,E>& mymap, const T& elem)
{
  return mymap.find(elem) != mymap.end();
}

/********************************
 Overloads for string (char)
*********************************/

inline bool contains__(const std::string& mystring, char c)
{
  for (const char it : mystring)
  {
    if (it == c)
      return true;
  }
  return false;
}

inline bool contains__(const char* mystring, char c)
{
  std::string str = mystring;
  for (const char it : str)
  {
    if (it == c)
      return true;
  }
  return false;
}

/********************************
 Overloads for string (string)
*********************************/

inline bool contains__(const std::string& mystring, const std::string &substring)
{
  return mystring.find(substring) != std::string::npos;
}

/********************************
 Overloads for string (char *)
*********************************/

inline bool contains__(const char *mystring, const std::string& substring)
{
  return std::string(mystring).find(substring) != std::string::npos;
}

inline bool contains__(const std::string& mystring, const char* substring)
{
  return mystring.find(std::string(substring)) != std::string::npos;
}

/********************************
 Overloads for char * (char *)
*********************************/

inline bool contains__(const char *mystring, const char* substring)
{
  return std::string(mystring).find(std::string(substring)) != std::string::npos;
}

/********************************
 Overloads for char * (vector)
*********************************/

inline bool contains__(const std::vector<std::string>& svec, const char* s)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

/********************************
 Overloads for char * (set)
*********************************/

inline bool contains__(const std::set<std::string>& svec, const char *s)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

/********************************
 Overloads for char * (map)
*********************************/

template <class T>
inline bool contains__(const std::map<std::string, T>& mymap, const char* s)
{
  return mymap.find(std::string(s)) != mymap.end();
}

/*****************************************
 Overloads for char * (initializer_list)
******************************************/

inline bool contains__(const std::initializer_list<std::string>& list, const char* s)
{
  std::string str(s);
  for (const std::string& it : list)
  {
    if (it == s)
      return true;
  }
  return false;
}

/***********************************************************
 Deleted functions (first argument bool could be an error)
************************************************************/
template <class T> inline bool contains__(const T& v1, const T& v2) = delete;  // NOTE: "x in y" has not sense when both have the same type
inline bool contains__(const std::string&, bool) = delete;  // NOTE: use "x not_in y" instead of: "! x in y"
inline bool contains__(const std::vector<bool>&, bool) = delete; // NOTE: "in" operator is not compatible with bool

template <typename A, typename B> inline bool not_contains__(const A &v1, const B &v2) {return !contains__(v1,v2);}

/************************************
 Definition of the operators
*************************************/
namespace pylike_named_operator_in
{
  template<class D>struct make_operator{make_operator(){}};

  template<class T, char, class O> struct half_apply { T&& lhs; };

  template<class Lhs, class Op>
  inline half_apply<Lhs, '*', Op> operator<( Lhs&& lhs, make_operator<Op> ) {
    return {std::forward<Lhs>(lhs)};
  }

  template<class Lhs, class Op, class Rhs>
  inline auto operator>( half_apply<Lhs, '*', Op>&& lhs, Rhs&& rhs )
  -> decltype( named_invoke( std::forward<Lhs>(lhs.lhs), Op{}, std::forward<Rhs>(rhs) ) )
  {
    return named_invoke( std::forward<Lhs>(lhs.lhs), Op{}, std::forward<Rhs>(rhs) );
  }
}
namespace pylike_in_helper_in {
  struct in_t : pylike_named_operator_in::make_operator<in_t> {};
  template<class T, class C>
  inline bool named_invoke( T&& t, in_t, C&& c ) {
    return contains__(const_cast<const C&&>(c), const_cast<const T&&>(t));
  }

  // Cases involving char* must be treated specifically
  template<class C>
  inline bool named_invoke(char *t, in_t, C&& c) {
    return contains__(const_cast<const C&&>(c), const_cast<const char*>(t));
  }
  template<class T>
  inline bool named_invoke(T&& t, in_t, char *c) {
    return contains__(const_cast<const char*>(c), const_cast<const T&&>(t));
  }
  inline bool named_invoke(char *t, in_t, char *c) {
    return contains__(const_cast<const char*>(c), const_cast<const char*>(t));
  }
  template<class C>
  inline bool named_invoke(const char *t, in_t, C&& c) {
    return contains__(const_cast<const C&&>(c), const_cast<const char*>(t));
  }
  template<class T>
  inline bool named_invoke(T&& t, in_t, const char *c) {
    return contains__(const_cast<const char*>(c), const_cast<const T&&>(t));
  }
  inline bool named_invoke(const char *t, in_t, const char *c) {
    return contains__(const_cast<const char*>(c), const_cast<const char*>(t));
  }

  inline bool named_invoke(char t, in_t, char* c) {
    return contains__(const_cast<const char*>(c), t);
  }

  inline bool named_invoke(char t, in_t, const char* c) {
    return contains__(const_cast<const char*>(c), t);
  }
}

namespace pylike_named_operator_not_in
{
  template<class D>struct make_operator{make_operator(){}};

  template<class T, char, class O> struct half_apply { T&& lhs; };

  template<class Lhs, class Op>
  inline half_apply<Lhs, '*', Op> operator<( Lhs&& lhs, make_operator<Op> ) {
    return {std::forward<Lhs>(lhs)};
  }

  template<class Lhs, class Op, class Rhs>
  inline auto operator>( half_apply<Lhs, '*', Op>&& lhs, Rhs&& rhs )
  -> decltype( named_invoke( std::forward<Lhs>(lhs.lhs), Op{}, std::forward<Rhs>(rhs) ) )
  {
    return named_invoke( std::forward<Lhs>(lhs.lhs), Op{}, std::forward<Rhs>(rhs) );
  }
}
namespace pylike_in_helper_not_in {
  struct not_in_t : pylike_named_operator_not_in::make_operator<not_in_t> {};
  template<class T, class C>
  inline bool named_invoke( T&& t, not_in_t, C&& c ) {
    return not_contains__(c, t);
  }
}

namespace in_operator
{
static pylike_in_helper_in::in_t in;
static pylike_in_helper_not_in::not_in_t not_in;
}

#endif // IN_OPERATOR_H_