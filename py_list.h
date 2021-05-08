#ifndef PY_LIST_H_
#define PY_LIST_H_

#include <vector>
#include <limits>

// USE:
// using namespace py_list
// vector<int> v1 = {1,2,3,4,5};
// vector<int> v2 = V(v1)[{1,3}];   // Like v1[1:3]
// int i = V(v1)[-1];   // Like v1[-1]

namespace py_list
{
  struct ind3
  {
    long i1;
    long i2;
    long i3 = 1;
  };

  constexpr int end() {return std::numeric_limits<int>::max();}

  template <class T>
  class Vcl
  {
  public:
    std::vector<T>& v;
    Vcl(std::vector<T>& a) : v(a) {}
    T operator[](long i) { if (i<0) i = v.size()+i; return v.at(i);}
    std::vector<T> operator[](ind3 x)
    {
      if (x.i3 == 0)
        throw;
      if (x.i2 == end())
        x.i2 = v.size();
      if (x.i1 < 0)
        x.i1 = x.i1 + v.size();
      if (x.i2 < 0)
        x.i2 = x.i2 + v.size();
      std::vector<T> res;
      if (x.i3 > 0)
      {
        for (int i=x.i1; i<x.i2; i+=x.i3)
          res.push_back(v[i%v.size()]);
      }
      else
      {
        for (int i=x.i2; i>x.i1; i+=x.i3)
          res.push_back(v.at(i%v.size()));
      }
      return res;
    }
  };

  template <class T>
  Vcl<T> V(std::vector<T> &a) {Vcl<T> v(a); return v;}
}


#endif // PY_LIST_H_