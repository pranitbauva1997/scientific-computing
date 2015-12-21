#include<stdio.h>

double f_dash(double x, double y){
    double temp;
    // Apply some function in temp;
    temp = 3*x*x;
    return temp;
}

double midpoint_euler(double x0, double y0, double xf, long steps);

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
    yf = midpoint_euler(x0, y0, xf, steps);
    printf("The value of y at x = %lf is %lf\n", xf, yf);
    return 0;
}

double midpoint_euler(double x0, double y0, double xf, long steps){
    double *x = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k1 = (double *) malloc((size_t) (steps * sizeof(double)));
    double *k2 = (double *) malloc((size_t) (steps * sizeof(double)));
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
        y[i] = y[i-1] + k2[i-1];
    }

    return y[steps - 1];
}
