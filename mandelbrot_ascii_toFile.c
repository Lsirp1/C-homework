#include <stdio.h>
#include "functions.h"

int mandelbrot (double a, double b){
    

    double x = 0.0; 
    double y = 0.0;
    double* ptrX = &x; 
    double* ptrY = &y;

    int d = 1000;
    for(int i = 0; i < 1000; i++) {

        compute(a, b, ptrX, ptrY);
        if(x * x + y * y > 4){
            d = i;
            break;
        }
        
        
    }
    return d;

}

void compute(double a, double b, double* xPtr, double* yPtr){

        double x = *xPtr;
        double y = *yPtr;

        double xTemp = x*x - y*y + a;
        double yTemp = 2*x*y + b;

        *xPtr = xTemp;
        *yPtr = yTemp;



}

void writeMandelbrot(double a, double b){

    FILE* fp = fopen("mandelbrot.txt", "w");
    for(int i = 0; i < 80; i ++){
        double bval = b - 1.0 + 2.0 * i/79.0;
        for(int j = 0; j < 80; j ++){
            double aval = a - 1.5 + 3.0 * j/79.0;
            int check = mandelbrot(aval, bval);
            if (check == 1000){
                fprintf(fp, "*");
            }
            else{
                fprintf(fp, " ");
            }

        }
        fprintf(fp, "\n");
    }
    fclose(fp); // I CLOSED THE FILE :)
}