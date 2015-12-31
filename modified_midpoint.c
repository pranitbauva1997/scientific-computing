#include<stdio.h>
#include<stdlib.h>
#include "ode.h"

double modified_midpoint(double x0, double y0, double xf, long steps){
    double *x = (double *) malloc((size_t) (steps * sizeof(double)));
    double *y = (double *) malloc((size_t) (steps * sizeof(double)));
    if(!x && !y){
        fprintf(stderr, "Sorry there was some problem allocating memory for the program.");
        exit(EXIT_FAILURE);
    }
    x[0] = x0;
    x[steps] = xf;
    y[0] = y0;
    int i;
    double h = (xf-x0)/steps;

    y[1] = y0 + h*f_dash(x0, y0);

    for(i = 1; i < steps - 1; i++){
        y[i+1] = y[i-1] + 2*h*(f_dash(x0 + h*i, y[i]));
    }

    double yf = (y[steps - 1] + y[steps - 2] + h*f_dash(xf, y[steps - 1]))/2;
    free(x);
    free(y);
    return yf;
}
