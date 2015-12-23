#include<stdio.h>
#include "ode.h"

double f_dash(double x, double y){
    double temp;
    // Apply some function in temp;
    temp = 3*x*x;
    return temp;
}

int main(int argc, char **argv){
    double x0, xf, y0, yf;
    long steps = 1;
    printf("Enter the initial value of x and y : ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter the final value of x : ");
    scanf("%lf", &xf);
    printf("Enter the no. of steps you want to perform : ");
    scanf("%ld", &steps);
    double h = (xf-x0)/steps;
    if(h == 0){
        printf("Sorry the step size was extremely small and it would trigger an infinite loop");
        return -1;
    }
    yf = simple_euler(x0, y0, xf, steps);
    printf("The value of y at x (Simple Euler)= %lf is %lf\n", xf, yf);
    yf = midpoint_euler(x0, y0, xf, steps);
    printf("The value of y at x (Mid Point Euler) = %lf is %lf\n", xf, yf);
    return 0;
}

