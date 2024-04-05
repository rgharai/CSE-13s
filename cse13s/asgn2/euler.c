#include "mathlib.h"

#include <stdio.h>

//The former function will approxi-mate the value ofπusing the formula derived
//from Euler’s solution to the Basel problem, as described in §4.4.
//Itshould also track the number of computed terms

static int count = 0;
double pi_euler(void) {
    double total = 0;
    double k = 1;
    while (1 / (k * k) > EPSILON) {
        total += 1 / (k * k);
        k += 1;
        count += 1;
    }
    return sqrt_newton(6 * total);
}

//The latter function will simply return the number of computedterms.
int pi_euler_terms(void) {
    return count;
}
