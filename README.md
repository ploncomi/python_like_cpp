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

This project is maintained by Patricio Loncomilla. The code is under MIT license

The codes in this repository requires at least C++11 to compile

Vector comprehensions are also compatible with range( ) from https://github.com/whoshuu/cpp_range

Notes: the main actual difficulty with these codes is that reported compilation errors when misusing operators "in" and "not_in" are too verbose. Then, locating the line which cause the error is not easy. However, source code using "in" and "not_in" is easily readable.

Also, it is recommended to include the files in this repository after all the other #include statements. This could be needed because other headers could use the word "in" for other uses. However, in and not_in can be turned off by using #undef in and #undef not_in

split() and strip() equivalent versions do exist in the Boost libraries, but use of Boost requires more verbose code. Also, split() in boost can only handle individual characters for splitting strings.

There are possible bugs in split(), it must be revised further
