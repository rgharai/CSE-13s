#include "mathlib.h"

#include <stdio.h>
#include <stdlib.h>
#define EPSILON 1e-14

//The former function will approximate the value of eusing the Taylor series
//presented in §3 and track the number of computed
//terms by means of astaticvariablelocal to the file

static int count;
double e(void) {
    double s = 1;
    double pt = 1;
    for (int k = 1; pt > EPSILON; k++) {
        pt = (pt / k);
        s += pt;
        count += 1;
    }
    return s;
}

//The latter function will simply return the number of computed terms.
int e_terms(void) {
    return count;
}
