#include <iostream>
#include "in_operator.h"

// This variables are used for testing robustness of the code against external variables named "in" or "not_in"
int in = 5;
char *not_in = "asd";

int main(void)
{
  using namespace std;
  using namespace in_operator_L;  // For enabling function L()

  #define in <in_operator::in>  // Optional macro per function. Scope is used for disambiguating respect to "int in" defined above
  #define not_in <in_operator::not_in>  // Optional macro per function. Scope in_operator:: is used for disambiguating respect to "char *not_in" defined above

  cout << "Substring search:" << endl;
  if ("h" in "hola")
    cout << "  \"h\" is in \"hola\"" << endl;

  if ("ol" in "hola")
    cout << "  \"ol\" is in \"hola\"" << endl;

  if ("q" not_in "hola")
    cout << "  \"q\" is not in \"hola\"" << endl;

  cout << "Element search:" << endl;

  if (2 in vector<int>{1,2,3})
    cout << "  2 is in {1,2,3}" << endl;

  if (5 not_in vector<int>{1,2,3})
    cout << "  5 is not in {1,2,3}" << endl;

  if (3 in L({1,2,3}))
    cout << "  3 is in {1,2,3}" << endl;

  if ("token3" in std::vector<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token3\" is in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::vector<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token5\" is not in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::set<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token5\" is not in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::map<string, int>{{"token1",1}, {"token2",2}, {"token3",3}, {"token4",4}})
    cout << "  \"token5\" is not in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token1" in L({"token1", "token2", "token3", "token4"}))
    cout << "  \"token1\" is in {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  #undef in
  #undef not_in

  return 0;
}