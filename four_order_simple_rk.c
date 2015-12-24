#include<stdio.h>
#include<stdlib.h>
#include "ode.h"

double four_order_simple_rk(double x0, double y0, double xf, long steps){
    double *x = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k1 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k2 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k3 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k4 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *y = (double *) malloc((size_t) (steps * sizeof(double)));
    if(!x)
        if(!y)
            fprintf(stderr, "Sorry there was some problem allocating memory for the program.");
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
        k3[i] = h * f_dash(x[i] + h/2, y[i] + k2[i]/2);
        k4[i] = h * f_dash(x[i] + h/2, y[i] + k3[i]/2);
        y[i] = y[i-1] + k1[i-1]/6 + k2[i-1]/3 + k3[i-1]/3 + k4[i]/6;
    }

    double yf = y[steps - 1];
    free(x);
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(y);
    return yf;
}
