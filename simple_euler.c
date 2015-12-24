#include<stdlib.h>
#include<stdio.h>
#include "ode.h"

double simple_euler(double x0, double y0, double xf, long steps){
    double *x = (double *) malloc((size_t) (steps * sizeof(double)));
    double *y = (double *) malloc((size_t) (steps * sizeof(double)));
    if(!x)
        if(!y)
            fprintf(stderr, "Sorry there was some problem allocating memory for the program.");
    x[0] = x0;
    x[steps-1] = xf;
    y[0] = y0;
    int i;
    double h = (xf-x0)/steps;

    for(i = 0; i < steps; i++)
        x[i] = i*h + x0;

    for(i = 1; i < steps; i++)
        y[i] = y[i-1] + h * f_dash(x[i-1], y[i-1]);

    double yf = y[steps - 1];
    free(x);
    free(y);
    return yf;
}
