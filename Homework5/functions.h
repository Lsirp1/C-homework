#ifndef functions_h
#define functions_h

int mandelbrot (double a, double b);
void compute(double a, double b, double* xPtr, double* yPtr);
void fill(int width, int height, int** array,  double a_min, double a_max, double b_min, double b_max);
void generate_image(int width, int height, int ** array);
void write_MandelbrotPPM(int width, int height, const unsigned char* pixels);

#endif