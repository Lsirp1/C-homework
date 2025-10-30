#include "Image.h"
#include <iostream>
#include <fstream>

Image::Image(){

}

Image::Image(int width, int height){

    this->width = width;
    this->height = height;
}

Image::Image(const unsigned char* pixels, int width, int height){

    this->width = width;
    this->height = height;
    this->pixels = new unsigned char[width * height * 3];
}

Image::~Image(){

    delete[] pixels;
}

unsigned char* Image::readPPM(const char* filename){

   std::ifstream file(filename, std::ios::binary);
   if(!file.is_open()){
        std::cerr <<" Error opening file: " << filename << std::endl;
        return nullptr;
   }
  
    std::string format;
    file >> format; //Read the magic number (format)
    if(format != "P6"){ 
        std::cerr <<" Unsupported PPM format: " << format << std::endl;
        return nullptr;
    }

    file >> width >> height;
    if(width <= 0 || height <= 0){
        std::cerr <<" Invalid image dimensions: " << width << "x" << height << std::endl;
        return nullptr;
    }

    int maxColorValue = 0;
    file >> maxColorValue; //max color value

    if(maxColorValue != 255){
        std::cerr <<" Unsupported max color value: " << maxColorValue << std::endl;
        return nullptr;
    }

    file.ignore(1); //Skip whitespace

      if(pixels != nullptr){
        delete[] pixels;
    }

    pixels = new unsigned char[width * height * 3];
    file.read(reinterpret_cast<char*>(pixels), width * height * 3);

    if(!file){
        std::cerr <<" Error reading pixel data from file: " << filename << std::endl;
        delete[] pixels;
        pixels = nullptr;
        return nullptr;
    }

    file.close();

    return pixels;

    
}

void Image::writePPM(const char* filename) const{

     std::ofstream file(filename, std::ios::binary);
     if(!file.is_open()){
        std::cerr <<" Error opening file for writing: " << filename << std::endl;
        return;
     }

     file << "P6\n" << width << " " << height << "\n255\n";
     file.write(reinterpret_cast<const char*>(pixels), width * height * 3);
     if(!file){
        std::cerr <<" Error writing pixel data to file: " << filename << std::endl;
        return;
     }

     file.close();

}

Image& Image::operator+=(int value){

    for(int i = 0; i < width * height * 3; ++i){
        
        int newValue = pixels[i] + value;

        if(newValue > 255) newValue = 255;
        if(newValue < 0) newValue = 0;

        pixels[i] = static_cast<unsigned char>(newValue);

    }

    return *this;
}