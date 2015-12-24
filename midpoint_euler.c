#include<stdio.h>
#include<stdlib.h>
#include "ode.h"

double midpoint_euler(double x0, double y0, double xf, long steps){
    double *x = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k1 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k2 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *y = (double *) malloc((size_t) (steps * sizeof(double)));
    if(!x && !y && !k1 && !k2){
        fprintf(stderr, "Sorry there was some problem allocating memory for the program.");
        exit(EXIT_FAILURE);
    }
    x[0] = x0;
    x[steps] = xf;
    y[0] = y0;
    int i;
    double h = (xf-x0)/steps;
    k1[0] = h * f_dash(x[0], y[0]);
    k2[0] = h * f_dash(x[0] + h/2, y[0] + k1[0]/2);

    for(i = 1; i < steps; i++){
        x[i] = i*h + x0;
        k1[i] = h * f_dash(x[i], y[i]);
        k2[i] = h * f_dash(x[i] + h/2, y[i] + k1[i]/2);
        y[i] = y[i-1] + k2[i-1];
    }

    double yf = y[steps - 1];
    free(x);
    free(k1);
    free(k2);
    free(y);
    return yf;
}
