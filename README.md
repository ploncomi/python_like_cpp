# python_like_cpp

The objective of this project is to enable C++ to use python-like constructs. Examples:

1) Operator "in"
```
  if ("h" in "hola")
    cout << "  h is in hola" << endl;

  if ("q" not_in "hola")
      cout << "  q is not in hola" << endl;
  
  if (2 in vector<int>{1,2,3})
    cout << "  2 is in {1,2,3}" << endl;
   
  if (3 in L({1,2,3}))
    cout << "  3 is in {1,2,3}" << endl;
```

2) Vector comprehension (like list comprehensions)
```
  std::vector<int> vals = {6,7,8,9,10};
  VECTCOMP(2*x, int x, vals)
  VECTCOMP(2*x, int x, {1,2,3,4,5})
  VECTCOMPIF(x, int x, vals, if (x%2 == 0))
```

3) Simple split / strip of strings
```
strip("   has spaces  ")
split("  there are some words ")
```

This project is maintained by Patricio Loncomilla. The code is under BSD license

The codes in this repository requires at least c++11 to compile

Vector comprehensions are also compatible with range( ) from https://github.com/whoshuu/cpp_range
