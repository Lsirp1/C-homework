#include <stdio.h>
#include <stdlib.h>

const unsigned char* readPPM(const char* filename, int* width, int* height){
    int maxColorValue = 0;

    FILE* fp = fopen(filename, "rb");

    if(fp == NULL){
        printf("Error opening file\n");
        return NULL;
        
    }
    char format[3];
    fscanf(fp, "%2s", format); //get the format
    fscanf(fp, "%d %d", width, height); //get width and height
    fscanf(fp, "%d", &maxColorValue); //get max color value
    fgetc(fp); // skip /n
    unsigned char* pixels = (unsigned char*) malloc((*width) * (*height) * 3);
    fread(pixels, 1, (*width) * (*height) * 3, fp);

    fclose(fp); //I CLOSED IT!! :)

    return pixels;
    
}

void writePPM(int width, int height, const unsigned char* pixels){

    FILE* fp = fopen("copy.ppm", "wb");

    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    
    fprintf(fp, "P6\n%d %d\n255", width, height);
    fwrite(pixels, 1, width * height * 3, fp);
    fclose(fp); // I CLOSED IT AGAIN SEE?? :P
}





    


