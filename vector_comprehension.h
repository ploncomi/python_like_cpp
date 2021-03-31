// 2021 Patricio Loncomilla

// For using VECTCOMP() with visual studio, the option /Zc:preprocessor must be used (or the option /experimental:preprocessor)
// However VECTCOMP3() and VECTCOMPIF() works without this flag

#ifndef VECTOR_COMPREHENSION_H_
#define VECTOR_COMPREHENSION_H_

//#if __cplusplus <= 199711 || __cplusplus <= 199711L
//#error The file vector_comprehension.h requires at least a c++11 compiler
//#endif

#include <vector>

// Normal case: vector or range
#define VECTCOMP3(expr, var, cont) [=](decltype(cont) w____) {var;std::vector<decltype(expr)> r____; for (var : w____) r____.push_back(expr);  return r____;}(cont)
// Case with braces
#define VECTCOMPN(expr, var, ...) [=](){var; std::vector<decltype(expr)> r____; for (var : __VA_ARGS__) r____.push_back(expr); return r____;}()
// Case selector
#define LCNAME(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,NAME, ...) NAME
// General call
#define VECTCOMP(...) LCNAME(__VA_ARGS__, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMPN, VECTCOMP3, NONE, NONE)(__VA_ARGS__)

// Conditional, does not support brackets
#define VECTCOMPIF(expr, var, cont, cond) [=](decltype(cont) w____) {var; std::vector<decltype(expr)> r____; for (var : w____) cond r____.push_back(expr); return r____;}(cont)

#endif // VECTOR_COMPREHENSION_H_