#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void fill(int width, int height, int** array,  double a_min, double a_max, double b_min, double b_max){

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            double a = a_min + (a_max - a_min) * j/(double)(width - 1);
            double b = b_min + (b_max - b_min) * i/(double)(height - 1);
            array[i][j] = mandelbrot(a, b);
        }
    }
}

void generate_image(int width, int height, int ** array){

    unsigned char* pixels = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            int index = (i * width + j) * 3;
            int value = array[i][j];
            pixels[index] = value;
            pixels[index + 1] = value;
            pixels[index + 2] = value;
        }
    }

    write_MandelbrotPPM(width, height, pixels);
    free(pixels);
}

void write_MandelbrotPPM(int width, int height, const unsigned char* pixels){

    FILE* fp = fopen("mandelbrot.PPM", "wb");

    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(pixels, 1, width * height * 3, fp);
    fclose(fp); // I CLOSED IT AGAIN SEE?? :P
}
