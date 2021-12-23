// 2021 Patricio Loncomilla
// License: MIT

#ifndef SPLIT_STRIP_H_
#define SPLIT_STRIP_H_

#include <string>
#include <vector>
#include <sstream>
#include <initializer_list>


// Functions provided:
// strip()
// split()
// replace()

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
  size_t i1=0, i2=s.size()-1;
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

  //for(const std::string &d : delims)
  //{
  //  tostrip += d;
  //}
  //s = strip(str, tostrip); 
  //if (s == "")
  //  return sarr;
  s = str;

  size_t i = 0;
  while (i < s.size())
  {
    bool inside_token = false;  // This variable indicates if inside a separator or inside a token

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
          i += d.size() - 1;
        }
      }
      if (i < s.size() && inside_token == true)
      {
        ss << s[i];
      }
      i++;
    }
    if (ss.str().size() > 0)
      sarr.push_back(ss.str().c_str());
  }
  return sarr;
}

inline std::vector<std::string> split(const std::string &str, const std::initializer_list<std::string>& delims)
{
  return split(str, std::vector<std::string>(delims));
}

std::vector<std::string> split (std::string s, std::string delimiter)
{
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos)
  {
    token = s.substr (pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back (token);
  }

  res.push_back (s.substr (pos_start));
  return res;
}

std::string join(std::string delimiter, std::vector<std::string> tokens)
{
  if (tokens.size() == 0)
    return "";
  std::stringstream str;

  for (size_t i=0; i<tokens.size()-1; i++)
    str << tokens[i] << delimiter;
  str << tokens[tokens.size()-1];
  return str.str();
}



std::string replace(std::string subject, const std::string& search, const std::string& replace)
{
  size_t pos = 0;
  while ((pos = subject.find(search, pos)) != std::string::npos)
  {
    subject.replace(pos, search.length(), replace);
    pos += replace.length();
  }
    return subject;
}  


} // namespace pl_split_strip

#endif // SPLIT_STRIP_H_
