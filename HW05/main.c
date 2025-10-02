#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){

    int width = 0;
    int height = 0; 

    double a_min = -2.0;
    double a_max = 1.0;
    double b_min = -1.5;    
    double b_max = 1.5;

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int** array = (int**) malloc(height * sizeof(int*));
    int* data = (int*) malloc(height * width * sizeof(int));

    for(int i = 0; i < height; i ++){
        array[i] = data + (i * width);
    }

    fill(width, height, array, a_min, a_max, b_min, b_max);
    generate_image(width, height, array);

    free (array);
    free (data);

}
