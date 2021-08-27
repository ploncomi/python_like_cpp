#include <iostream>
#include "in_operator.h"

int main(void)
{
  using namespace std;
  using namespace in_operator_L;  // For enabling function L()

  // Option 1: using defines
  // This option will shadow preexistent variables named in and not_in

  #define in <in_operator::in> 
  #define not_in <in_operator::not_in>

  cout << "Substring search:" << endl;
  if ('h' in "hola")
    cout << "  \'h\' is in \"hola\"" << endl;

  if ("ol" in "hola")
    cout << "  \"ol\" is in \"hola\"" << endl;

  if (std::string("q") not_in "hola")
    cout << "  \"q\" is not in \"hola\"" << endl;

  cout << "Element search:" << endl;

  if (2 in vector<int>{1,2,3})
    cout << "  2 is in vector {1,2,3}" << endl;

  if (5 not_in vector<int>{1,2,3})
    cout << "  5 is not in vector {1,2,3}" << endl;

  if (3 in L({1,2,3}))
    cout << "  3 is in initializer list {1,2,3}" << endl;

  if ("token3" in std::vector<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token3\" is in vector {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::vector<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token5\" is not in vector {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::set<string>{"token1", "token2", "token3", "token4"})
    cout << "  \"token5\" is not in set {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token5" not_in std::map<string, int>{{"token1",1}, {"token2",2}, {"token3",3}, {"token4",4}})
    cout << "  \"token5\" is not in map {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  if ("token1" in L({"token1", "token2", "token3", "token4"}))
    cout << "  \"token1\" is in initializer list {\"token1\", \"token2\", \"token3\", \"token4\"}" << endl;

  #undef in
  #undef not_in

  // Option 2: using namespaces and < > brackets
  // This option will fail to compile if there are other variables named "in" or "not_in"

  using namespace in_operator;

  if ('h' <in> "hola")
    cout << "  \'h\' is in \"hola\"" << endl;

  if ("qwe" <not_in> "hola")
    cout << "  \"qwe\" is not in \"hola\"" << endl;


  return 0;
}
