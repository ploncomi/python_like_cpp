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
   
  if (5 not_in L({1,2,3}))
    cout << "  5 is not in {1,2,3}" << endl;
```

2) Vector comprehension (like list comprehensions)
```
  std::vector<int> vals = {6,7,8,9,10};
  auto v1 = VECTCOMP(2*x, int x, vals);
  auto v2 = VECTCOMP(2*x, int x, {1,2,3,4,5});
  auto v3 = VECTCOMPIF(x, int x, vals, if (x%2 == 0));
```

3) Simple split / strip of strings
```
strip("   has spaces  ")
split("  there are some words ")
```

This project is maintained by Patricio Loncomilla. The code is under MIT license

The codes in this repository requires at least C++11 to compile

Vector comprehensions are also compatible with range( ) from https://github.com/whoshuu/cpp_range

Notes:

1) This is a toy code...

2) The main actual difficulty with these codes is that reported compilation errors when misusing operators "in" and "not_in" are not informative enough (specially when using g++). However, source code using "in" and "not_in" is easily readable.

3) Use of in and not_in operators require using defines before being used:
```
#define in <in_operator::in>
#define not_in <in_operator::not_in>
// Code using in and not_in
// Note that preexstent variables named "in" and "not_in" will be shadowed by the defines
#undef in
#undef not_in
```

4) split() and strip() equivalent versions do exist in the Boost libraries, but use of Boost requires more verbose code. Also, split() in boost can only handle individual characters for splitting strings.

5) There are possible bugs in split(), it must be revised further
