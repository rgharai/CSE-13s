#include "mathlib.h"

#include <stdio.h>

// The former function willapproximate the the square root of the argument
//passed to it using the Newton-Raphson method presented in §5.
static int count;
double sqrt_newton(double x) {
    double z = 0.0;
    double y = 1.0;
    while (absolute(y - z) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
        count += 1;
    }
    return y;
}

//This function should also track the number of iterations taken,
//which the latter function will return.
int sqrt_newton_iters(void) {
    return count;
}
