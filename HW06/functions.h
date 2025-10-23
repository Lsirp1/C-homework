#ifndef FUNCTIONS_H
#define FUNCTIONS_H 

unsigned char* readPPM(const char* filename, int* width, int* height);
void convertToJPEG(const char* filename, const unsigned char* pixels, const int width, const int height);

#endif