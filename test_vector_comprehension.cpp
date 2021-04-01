#include <iostream>
#include <string>
#include "vector_comprehension.h"

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
  using namespace std;
  std::vector<int> vals = {6,7,8,9,10};

  cout << VECTCOMP(2*x, int x, vals) << endl;
  cout << VECTCOMP(2*x, int x, {1,2,3,4,5}) << endl;
  cout << VECTCOMP("Numero "+to_string(x), int x, vals) << endl;
  cout << VECTCOMP(x, int x, vals) << endl;
  cout << VECTCOMPIF(x, int x, vals, if (x%2 == 0)) << endl;

  return 0;
}

