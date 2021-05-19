// 2021 Patricio Loncomilla

#ifndef IN_OPERATOR_H_
#define IN_OPERATOR_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <initializer_list>

//#include <type_traits>

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
template <class T, class E>
inline bool in__(const T& elem, const E& other)
{
  static_assert(false, "\"in\" operator used on invalid types (see file: in_operator.h)");
  return false;
}

/***************
 Overloads for vector
****************/
template <class T>
inline bool in__(const T& elem, const std::vector<T>& vect)
{
  for (const T& it : vect)
  {
    if (it == elem)
      return true;
  }
  return false;
}

template <class T>
inline bool in__(T& elem, const std::vector<T>& vect)
{
  for (const T& it : vect)
  {
    if (it == elem)
      return true;
  }
  return false;
}

template <class T>
inline bool in__(const T& elem, std::vector<T>& vect)
{
  for (const T& it : vect)
  {
    if (it == elem)
      return true;
  }
  return false;
}

template <class T>
inline bool in__(T& elem, std::vector<T>& vect)
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
inline bool in__(const T& elem, const std::initializer_list<T>& list)
{
  for (const T& it : list)
  {
    if (it == elem)
      return true;
  }
  return false;
}

template <class T>
inline bool in__(T& elem, const std::initializer_list<T>& list)
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
inline bool in__(const T& elem, const std::set<T>& myset)
{
  return myset.find(elem) != myset.end();
}

template <class T>
inline bool in__(T& elem, const std::set<T>& myset)
{
  return myset.find(elem) != myset.end();
}

template <class T>
inline bool in__(const T& elem, std::set<T>& myset)
{
  return myset.find(elem) != myset.end();
}

template <class T>
inline bool in__(T& elem, std::set<T>& myset)
{
  return myset.find(elem) != myset.end();
}

/********************************
 Overloads for map
*********************************/

template <class T, class E>
inline bool in__(const T& elem, const std::map<T,E>& mymap)
{
  return mymap.find(elem) != mymap.end();
}

template <class T, class E>
inline bool in__(const T& elem, std::map<T,E>& mymap)
{
  return mymap.find(elem) != mymap.end();
}

template <class T, class E>
inline bool in__(T& elem, const std::map<T,E>& mymap)
{
  return mymap.find(elem) != mymap.end();
}

template <class T, class E>
inline bool in__(T& elem, std::map<T,E>& mymap)
{
  return mymap.find(elem) != mymap.end();
}


/********************************
 Overloads for string (char)
*********************************/

inline bool in__(char c, const std::string& mystring)
{
  for (const char it : mystring)
  {
    if (it == c)
      return true;
  }
  return false;
}

inline bool in__(char c, std::string& mystring)
{
  for (const char it : mystring)
  {
    if (it == c)
      return true;
  }
  return false;
}

inline bool in__(char c, const char *mystring)
{
  std::string str = mystring;
  for (const char it : str)
  {
    if (it == c)
      return true;
  }
  return false;
}

inline bool in__(char c, char *mystring)
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

inline bool in__(const std::string &substring, const std::string& mystring)
{
  return mystring.find(substring) != std::string::npos;
}

inline bool in__(std::string &substring, const std::string& mystring)
{
  return mystring.find(substring) != std::string::npos;
}

inline bool in__(const std::string &substring, std::string& mystring)
{
  return mystring.find(substring) != std::string::npos;
}

inline bool in__(std::string &substring, std::string& mystring)
{
  return mystring.find(substring) != std::string::npos;
}


/********************************
 Overloads for string (char *)
*********************************/

inline bool in__(const std::string &substring, const char *mystring)
{
  return std::string(mystring).find(substring) != std::string::npos;
}

inline bool in__(std::string &substring, const char *mystring)
{
  return std::string(mystring).find(substring) != std::string::npos;
}

inline bool in__(const std::string &substring, char *mystring)
{
  return std::string(mystring).find(substring) != std::string::npos;
}

inline bool in__(std::string &substring, char *mystring)
{
  return std::string(mystring).find(substring) != std::string::npos;
}

inline bool in__(const char *substring, const std::string& mystring)
{
  return mystring.find(std::string(substring)) != std::string::npos;
}

inline bool in__(char *substring, const std::string& mystring)
{
  return mystring.find(std::string(substring)) != std::string::npos;
}

inline bool in__(const char *substring, std::string& mystring)
{
  return mystring.find(std::string(substring)) != std::string::npos;
}

inline bool in__(char *substring, std::string& mystring)
{
  return mystring.find(std::string(substring)) != std::string::npos;
}


/********************************
 Overloads for char * (vector)
*********************************/

inline bool in__(const char *substring, const char *mystring)
{
  return std::string(mystring).find(std::string(substring)) != std::string::npos;
}

inline bool in__(char *substring, const char *mystring)
{
  return std::string(mystring).find(std::string(substring)) != std::string::npos;
}

inline bool in__(const char *substring, char *mystring)
{
  return std::string(mystring).find(std::string(substring)) != std::string::npos;
}

inline bool in__(char *substring, char *mystring)
{
  return std::string(mystring).find(std::string(substring)) != std::string::npos;
}


/********************************
 Overloads for char * (vector)
*********************************/

inline bool in__(const char *s, const std::vector<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(char *s, const std::vector<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(const char *s, std::vector<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(char *s, std::vector<std::string>& svec)
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

inline bool in__(const char *s, const std::set<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(char *s, const std::set<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(const char *s, std::set<std::string>& svec)
{
  std::string str(s);
  for (const std::string& it : svec)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(char *s, std::set<std::string>& svec)
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
inline bool in__(const char *s, const std::map<std::string, T>& mymap)
{
  return mymap.find(std::string(s)) != mymap.end();
}

template <class T>
inline bool in__(char *s, const std::map<std::string, T>& mymap)
{
  return mymap.find(std::string(s)) != mymap.end();
}

template <class T>
inline bool in__(const char *s, std::map<std::string, T>& mymap)
{
  return mymap.find(std::string(s)) != mymap.end();
}

template <class T>
inline bool in__(char *s, std::map<std::string, T>& mymap)
{
  return mymap.find(std::string(s)) != mymap.end();
}


/*****************************************
 Overloads for char * (initializer_list)
******************************************/

inline bool in__(const char *s, const std::initializer_list<std::string>& list)
{
  std::string str(s);
  for (const std::string& it : list)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(char *s, const std::initializer_list<std::string>& list)
{
  std::string str(s);
  for (const std::string& it : list)
  {
    if (it == s)
      return true;
  }
  return false;
}

inline bool in__(const char *s, const std::initializer_list<const char *>& list)
{
  std::string str(s);
  for (const std::string& it : list)
  {
    if (in__(s, it))
      return true;
  }
  return false;
}

inline bool in__(char *s, const std::initializer_list<const char *>& list)
{
  std::string str(s);
  for (const std::string& it : list)
  {
    if (in__(s, it))
      return true;
  }
  return false;
}


/***********************************************************
 Deleted functions (first argument bool could be an error)
************************************************************/
template <class T> inline bool in__(const T& v1, const T& v2) = delete;  // NOTE: "x in y" has not sense when both have the same type
inline bool in__(bool, const std::string&) = delete;  // NOTE: use !(x in y) instead of: ! x in y
inline bool in__(bool, const std::vector<bool>&) = delete; // NOTE: "in" is not compatible with bool

template <typename A, typename B> inline bool not_in__(const A &v1, const B &v2) {return !in__(v1,v2);}

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
    return in__(t, c);
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
    return not_in__(t, c);
  }
}

namespace in_operator
{
static pylike_in_helper_in::in_t in;
static pylike_in_helper_not_in::not_in_t not_in;
}

#endif // IN_OPERATOR_H_