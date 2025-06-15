#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Raise an integer base to an unsigned exponent
long long power(int base, unsigned exp);

// Compute factorial n! (supports 0! = 1).
// Note: for n > 20 the result may overflow a 64-bit value.
long long factorial(unsigned n);

// Absolute value of an integer
int abs_val(int x);

#endif // MATH_UTILS_H
