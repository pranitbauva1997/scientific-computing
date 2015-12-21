#include<stdio.h>

double f_dash(double x, double y){
    double temp;
    // Apply some function in temp;
    temp = 3*x*x/y/2;
    return temp;
}

double simple_euler(double x0, double y0, double xf, long steps);

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
    printf("The value of y at x = %lf is %lf\n", xf, yf);
    return 0;
}

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

    return y[steps - 1];
}
