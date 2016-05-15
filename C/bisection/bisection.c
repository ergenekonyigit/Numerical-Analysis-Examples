#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITER 200
#define ERROR 1e-10

/*
 * f : R -> R is a continuous function on all reals with the 
 * property that f(sqrt(2)) = f(-sqrt(2)) = 0.
 */
double f(double x) {
    return x*x - 2.0;
}



/*
 * Bisection method root finder.
 */
double bisect(double (*func)(double), double lower, double upper) {
    // So we can assume that lower <= upper later
    if (func(lower) > func(upper)) {
        int tmp = lower;
        lower = upper;
        upper = tmp;
    }
    int iter = 0;
    double midpoint;
    do {
        midpoint = 0.5 * lower + 0.5 * upper;
        if (fabs(func(midpoint)) < ERROR) {
            return midpoint;
        }
        else if (func(midpoint) < 0) {
            lower = midpoint;
        }
        else {
            upper = midpoint;
        }
        iter ++;
    }
    while (iter < MAX_ITER);

    fprintf(stderr, "No root detected!\n");
    exit(1);

}

/*
 * Main procedure. Specifies usage and parses command line arguments for search
 * bounds.
 */
int main(int argc, char ** argv) {
    // Ensures that the necessary arguments are present
    if (argc!= 3) {
        fprintf(stderr, "Usage:\n\t./bisection.o lower upper\n");
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    double lower = atof(argv[1]);
    double upper = atof(argv[2]);

    // Specify the function you want to bisect here.
    double (*func)(double) = f;

    double result = bisect(func, lower, upper);

    fprintf(stdout, "Root of g on interval [%0.4lf, %0.4lf]:\n", lower, upper);
    fprintf(stdout, "%0.10lf\n", result);
    exit(0);
}
