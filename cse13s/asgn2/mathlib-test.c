#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#define OPTIONS "aebmrvnsh"
double e(void);
double pi_euler(void);
double pi_bbp(void);
double pi_madhava(void);
double pi_viete(void);
double sqrt_newton(double);

int main(const int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            //Runs all tests
            printf(
                "e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E, absolute(e() - M_E));

            printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI,
                absolute(pi_bbp() - M_PI));

            printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(),
                M_PI, absolute(pi_madhava() - M_PI));

            printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(), M_PI,
                absolute(pi_euler() - M_PI));

            printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(), M_PI,
                absolute(pi_viete() - M_PI));

            for (double x = 0; x < 10; x += 0.1) {
                printf("sqrt_newton(%lf) = %16.15lf, sqrt(%lf) = %16.15lf, diff = %16.15lf\n", x,
                    sqrt_newton(x), x, sqrt(x), absolute(sqrt_newton(x) - sqrt(x)));

                break;
            case 'e':
                //Runs e approximation test.
                printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E,
                    absolute(e() - M_E));
                break;

            case 'b':
                // Runs Bailey-Borwein-Plouffeπapproximation test.

                printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI,
                    absolute(pi_bbp() - M_PI));
                break;

            case 'm':
                //Runs Madhavaπapproximation test.
                printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(),
                    M_PI, absolute(pi_madhava() - M_PI));
                break;

            case 'r':
                //Runs Euler sequenceπapproximation test
                printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(),
                    M_PI, absolute(pi_euler() - M_PI));
                break;

            case 'v':
                //Runs Vièteπapproximation test.
                printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(),
                    M_PI, absolute(pi_viete() - M_PI));
                break;

            case 'n':
                //Runs Newton-Raphson square root approximation tests.
                for (double x = 0; x < 10; x += 0.1) {
                    printf("sqrt_newton(%lf) = %16.15lf, sqrt(%lf) = %16.15lf, diff = %16.15lf\n",
                        x, sqrt_newton(x), x, sqrt(x), absolute(sqrt_newton(x) - sqrt(x)));
                }
                break;

            case 's':
                //Enable printing of statistics to see computed terms
                //and factors for each tested function.
                printf("SYNOPSIS\n");
                printf("   A test harness for the small numerical libarary.\n");

                printf("USAGE\n");
                printf("   ./mathlib-test [-aebmrvnsh]\n");

                printf("OPTIONS\n");
                printf("   -a   Runs all tests.\n");
                printf("   -e   Runs e test.\n");
                printf("   -b   Runs BBP pi test.\n");
                printf("   -m  Runs Mashava pi test.\n");
                printf("   -r  Runs Euler pi test.\n");
                printf("   -v  Runs Viete pi test.\n");
                printf("   -n  Runs Newton square root tests.\n");
                printf("   -s  Print verbose statistics\n");
                printf("   -h  Display program synopsis and usage.\n");
                break;

            case 'h':
                //Display a help message detailing program usage.
                printf("SYNOPSIS\n");
                printf("   A test harness for the small numerical libarary.\n");

                printf("USAGE\n");
                printf("   ./mathlib-test [-aebmrvnsh]\n");

                printf("OPTIONS\n");
                printf("   -a   Runs all tests.\n");
                printf("   -e   Runs e test.\n");
                printf("   -b   Runs BBP pi test.\n");
                printf("   -m  Runs Mashava pi test.\n");
                printf("   -r  Runs Euler pi test.\n");
                printf("   -v  Runs Viete pi test.\n");
                printf("   -n  Runs Newton square root tests.\n");
                printf("   -s  Print verbose statistics\n");
                printf("   -h  Display program synopsis and usage.\n");
                break;
            }
        }
    }
}
