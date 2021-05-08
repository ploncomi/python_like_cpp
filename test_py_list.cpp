#include <iostream>
#include "py_list.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

int main(void)
{
  using namespace py_list;
  using namespace std;
  vector<int> a = {2,4,8,10,12,14};
  cout << V(a)[-1] << endl;
  cout << V(a)[{1,-1}] << endl;
  cout << V(a)[{2,end()}] << endl;

  return 0;
}







