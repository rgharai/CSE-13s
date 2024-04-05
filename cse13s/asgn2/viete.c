#include "mathlib.h"

#include <stdio.h>

//The former function will approx-imate the value ofπusing Viète’s formula
//as presented in §4.6 and track the number of computed factors.

static int count = 0;
double pi_viete() {
    double v1 = 0;
    double v2 = 1;

    while (1) {
        v1 = sqrt_newton(2 + v1);
        v2 = (v1 / 2 * v2);
        double tem = (v1 / 2);
        count += 1;
        if ((1 / tem - 1) < EPSILON) {
            double tem2 = 2 / v2;
            return tem2;
            break;
        }
    }
}

// Thelatter function will simply return the number of computed factors.
int pi_viete_factors() {
    return count;
}
