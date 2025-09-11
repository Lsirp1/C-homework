#include <stdio.h>
#include "functions.h"

int main(int argc, char ** argv){

    double a, b = 0.0;
    printf("Please enter an a value.\n");
    scanf("%lf", &a);
    printf("Please enter a b value.\n");
    scanf("%lf", &b);
    printMandelbrot(a, b);

}
