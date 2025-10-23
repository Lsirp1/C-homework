#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>

int main(){

    int width = 0;
    int height = 0;
    

    char filename[100];
    char jpegfilename[100];

    printf("Enter the filename of the PPM image: ");
    scanf("%99s", filename);

    unsigned char* ppM = readPPM(filename, &width, &height);

    if (ppM == NULL) {
        return 1; // Error reading PPM file
    }

    strcpy(jpegfilename, filename);
    char* dot = strrchr(jpegfilename, '.');
    if (dot != NULL) {
        strcpy(dot, ".jpg");
    } else {
        strcat(jpegfilename, ".jpg");
    }

    convertToJPEG(jpegfilename, ppM, width, height);

    free(ppM);

    return 0;
}