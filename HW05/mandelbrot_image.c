#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int mandelbrot (double a, double b){
    

    double x = 0.0; 
    double y = 0.0;

    int count = 255;
    for(int i = 0; i < 255; i++) {

        compute(a, b, &x, &y);
        if(x * x + y * y > 4){
            count = i;
            break;
        }
        
        
    }
    
    return count;

}

void compute(double a, double b, double* xPtr, double* yPtr){

        double x = *xPtr;
        double y = *yPtr;

        double xTemp = x*x - y*y + a;
        double yTemp = 2*x*y + b;

        *xPtr = xTemp;
        *yPtr = yTemp;



}
