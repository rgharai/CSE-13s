#include "mathlib.h"

#include <stdio.h>
//The former function will approximate thevalue ofπusing the Bailey-Borwein-Plouffe
//formula presented in §4.5 and track the number of computed terms

static int count = 0;

double pi_bbp() {
    double term = 1;
    double sum = 0;
    double num = 0;

    for (double x = 0; absolute(term) > EPSILON; x++) {
        if (x == 0) {
            num = 1;
        } else {
            num *= 16;
        }
        double f = 1 / num;
        term = (f)
               * (((4) / (8 * x + 1)) - ((2) / (8 * x + 4)) - ((1) / (8 * x + 5))
                   - ((1) / (8 * x + 6)));
        sum += term;
        count += 1;
    }
    return sum;
}

//The latter function will simply return the number of computed terms.
int pi_bbp_terms() {
    return count;
}
