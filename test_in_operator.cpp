#include "in_operator.h"
#include <iostream>


int main(void)
{
  using namespace std;

  // use of "in" operator

  cout << "Substring search:" << endl;
  if ("h" in "hola")
    cout << "  \"h\" is in \"hola\"" << endl;

  if ("ol" in "hola")
    cout << "  \"ol\" is in \"hola\"" << endl;

  if (!("q" in "hola"))
    cout << "  \"q\" is not in \"hola\"" << endl;

  cout << "Element search:" << endl;

  if (2 in vector<int>{1,2,3})
    cout << "  2 is in {1,2,3}" << endl;

  if ( !(5 in vector<int>{1,2,3}) )
    cout << "  5 is not in {1,2,3}" << endl;

  if (3 in L({1,2,3}))
    cout << "  3 is in {1,2,3}" << endl;

  if ("token3" in std::vector<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token3\" is in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ( !("token5" in std::vector<string>{"token1", "token2", "token3", "token4"}) )
    cout << "  \"token5\" is not in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token1" in L({"token1", "token2", "token3", "token4"}))
    cout << "  \"token1\" is in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  return 0;
}