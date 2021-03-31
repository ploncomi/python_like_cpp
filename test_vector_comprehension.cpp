#include <iostream>
#include <string>
#include "vector_comprehension.h"

#define nada(X) X;

template<class T>
void print_vector(const std::vector<T> &arr)
{
  for (const T& x : arr)
    std::cout << x << ", ";
  std::cout << std::endl;
}

int main(void)
{
  using namespace std;
  std::vector<int> vals = {6,7,8,9,10};
  double m = 1.5;

  nada(int x);

  auto f = []() {int x;};

  []() {int x;};

  print_vector( VECTCOMP(2*x, int x, vals) );
  print_vector( VECTCOMP(2*x, int x, {1,2,3,4,5}) );
  print_vector( VECTCOMP(string("Numero ")+to_string(x), int x, vals) );
  print_vector( VECTCOMP(x, int x, vals) );
  print_vector( VECTCOMPIF(x, int x, vals, if (x%2 == 0)) );

  return 0;
}

