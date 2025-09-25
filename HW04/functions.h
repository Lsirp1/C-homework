#ifndef functions_h
#define functions_h

unsigned char* readPPM(const char* filename, int* width, int* height);
void writePPM(int width, int height, unsigned char* pixels);

#endif