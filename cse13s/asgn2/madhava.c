#include "mathlib.h"

#include <stdlib.h>

//will ap-proximate the value ofπusing the Madhava
//series presented in §4.2 and track the number
//of computed terms withastaticvariable, exactly like ine.c

static int count = 0;
double pi_madhava(void) {
    double k = 0;
    double mul = -3;
    double up = 1;
    double pi_num = 0;
    int make_update = 1;
    while (k <= 10000) {
        for (int i = 0; i < k - 1; i++) {
            mul *= -3;
        }
        if (make_update == 1) {
            up = 1;
            make_update = 0;
        } else {
            up = 1 / mul;
            make_update = 0;
        }
        up *= 1 / ((2 * k) + 1);
        pi_num += up;
        k += 1;
        mul = -3;
        count += 1;
    }
    pi_num *= sqrt_newton(12);
    return pi_num;
}

//The latter function will simply return the number of computed terms.
int pi_madhava_terms(void) {
    return count;
}
