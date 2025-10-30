#ifndef IMAGE_H
#define IMAGE_H

class Image {

    private:
        int width = 0;
        int height = 0;
        unsigned char* pixels = nullptr;

    public:

        Image();
        Image(int width, int height);
        Image(const unsigned char *pixels, int width, int height);
        virtual ~Image();

       unsigned char* readPPM(const char* filename);
       void writePPM(const char* filename) const;
       Image& operator+=(int value);
        

};
#endif