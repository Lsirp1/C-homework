#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){

    int width = 0;
    int height = 0;
   

    char filename[100];

    printf("Enter the filename of the PPM image: ");
    scanf("%99s", filename);

    unsigned char* ppM = readPPM(filename, &width, &height);
    writePPM((width), (height), ppM);

    free(ppM);

    return 0;
}