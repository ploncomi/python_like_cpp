// 2021 Patricio Loncomilla

#ifndef SPLIT_STRIP_H_
#define SPLIT_STRIP_H_

//#if __cplusplus <= 199711 || __cplusplus <= 199711L
//#error The file split_strip.h requires at least a c++11 compiler
//#endif

#include <string>
#include <vector>
#include <sstream>
#include <initializer_list>

namespace pl_split_strip
{

inline bool in_fn_(char c, const std::string& mystring)
{
  for (const char it : mystring)
  {
    if (it == c)
      return true;
  }
  return false;
}


inline std::string strip(const std::string& s, const std::string &delims = " \n")
{
  if (s == "")
    return "";
  std::stringstream ss;
  int i1=0, i2=s.size()-1;
  while ( i1 < i2 && in_fn_(s[i1], delims))
    i1++;
  if (i1 == i2)
    return "";
  while(in_fn_(s[i2], delims))
    i2--;
  for (size_t i=i1; i<=i2; i++)
    ss << s[i];
  return ss.str();
}

inline bool coincide_internal(const std::string& a, const std::string& b)
{
  if (a.size() > b.size())
    return false;
  for (size_t i=0; i<a.size(); i++)
  {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

inline std::vector<std::string> split(const std::string &str, const std::vector<std::string>& delims = {" ", "\n"})
{
  std::vector<std::string> sarr;
  std::string tostrip;
  std::string s;

  for(const std::string &d : delims)
  {
    tostrip += d;
  }
  s = strip(str, tostrip); 
  if (s == "")
    return sarr;

  int i = 0;
  while (i < s.size())
  {
    bool inside_token = false;

    while (inside_token == false && i < s.size())
    {
      inside_token = true;
      for(const std::string &d : delims)
      {
        if (i < s.size() && coincide_internal(d, &s[i]))
        {
          i += d.size();
          inside_token = false;
        }
      }
    }
    std::stringstream ss;
    while (inside_token == true && i < s.size())
    {
      for(const std::string &d : delims)
      {
        if (i < s.size() && coincide_internal(d, &s[i]))
        {
          inside_token = false;
        }
      }
      if (i < s.size() && inside_token == true)
      {
        ss << s[i];
      }
      i++;
    }
    sarr.push_back(ss.str().c_str());
  }
  return sarr;
}

inline std::vector<std::string> split(const std::string &str, const std::initializer_list<std::string>& delims)
{
  return split(str, std::vector<std::string>(delims));
}

inline std::vector<std::string> split(const std::string &s, const std::string &delims)
{
  std::vector<std::string> sarr;
  sarr.push_back(delims);
  return split(s, sarr);
}

}

#endif // SPLIT_STRIP_H_