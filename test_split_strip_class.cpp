#include "split_strip_class.h"
#include <iostream>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
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
  cout << S("   has spaces  ").strip() << endl;
  cout << S("  there are some words ").split() << endl;
  cout << S("  there are some words ").split({"e", "o"}) << endl;  // Multiple delimiters
  cout << S("Hello all").split("l") << endl;    // Dont compress tokens
  cout << S("Hello all").split({"l"}) << endl;  // Compress tokens
  cout << S("l").join(S("Hello all").split("l")) << endl;

  cout << S("Some words").replace("Some", "No") << endl;

  cout << S("Some words").startswith("Some") << endl;
  cout << S("Some words").endswith("words") << endl;

  return 0;
}
