#include <stdio.h>
#include "functions.h"

int Mandelbrot (double a, double b){
    
    double x = 0.0, y = 0.0;
    int d = 1000;
    for(int i = 0; i < 1000; i++) {

        double xTemp = x*x - y*y + a;
        double yTemp = 2*x*y + b;
        x = xTemp;
        y = yTemp;

        if(x * x + y * y > 4){
            d = i;
            break;
        }
    }
    return d;

}

void printMandelbrot(double a, double b){

    for(int i = 0; i < 80; i ++){
        double bval = b - 1.0 + 2.0 * i/79.0;
        for(int j = 0; j < 80; j ++){
            double aval = a - 1.5 + 3.0 * j/79.0;
            int check = Mandelbrot(aval, bval);
            if (check == 1000){
                printf("*");
            }
            else{
                printf(" ");
            }

        }
        printf("\n");
    }
}
