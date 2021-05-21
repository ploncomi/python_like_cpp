#include "split_strip.h"
#include <iostream>

using namespace std;

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
  using namespace pl_split_strip;
  cout << strip("   has spaces  ") << endl;
  cout << split("  there are some words ") << endl;
  cout << split("  there are some words ", {"e", "o"}) << endl;  // Multiple delimiters
  cout << split("Hello all", "l") << endl;    // Dont compress tokens
  cout << split("Hello all", {"l"}) << endl;  // Compress tokens
  cout << join("l", split("Hello all", "l")) << endl;

  return 0;
}
