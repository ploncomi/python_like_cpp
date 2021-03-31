#include "split_strip.h"
#include <iostream>

using namespace std;

template<class T>
void print_vector(const std::vector<T> &arr)
{
  for (const T& x : arr)
    std::cout << x << ", ";
  std::cout << std::endl;
}

int main(void)
{
  using namespace pl_split_strip;
  cout << strip("   has spaces  ") << endl;
  print_vector( split("  there are some words ")  );
  print_vector( split("  there are some words ", {"e", "o"})  );
  print_vector( split("  there are some words ", {"er"})  );

  return 0;
}
