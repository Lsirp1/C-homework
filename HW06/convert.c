#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include "functions.h"

unsigned char* readPPM(const char* filename, int* width, int* height) {

    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Cannot open %s\n", filename);
        return NULL;
    }
    //magic number
    char magic[3];
    if (fscanf(fp, "%2s", magic) != 1 || magic[0] != 'P' || magic[1] != '6' || magic[2] != '\0') {
        printf("Not a PPM file: %s\n", filename);
        fclose(fp);
        return NULL;
    }
  
    if (fscanf(fp, "%d %d", width, height) != 2) {
        printf("Invalid image size in: %s\n", filename);
        fclose(fp);
        return NULL;
    }

    int maxval;
    if (fscanf(fp, "%d", &maxval) != 1) {
        printf("Invalid max pixel value in: %s\n", filename);
        fclose(fp);
        return NULL;
    }
    // skip the \n
    fgetc(fp);
    
    unsigned char* pixels = (unsigned char*)malloc(3 * (*width) * (*height));
    if (pixels == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return NULL;
    }
    fread(pixels, 1, (size_t)(3 * (*width) * (*height)), fp);
    fclose(fp);
    return pixels;
}

// writes a JPEG file using libjpeg
void convertToJPEG(const char* filename, const unsigned char* pixels, const int width, const int height) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE* outfile;
    JSAMPROW row_pointer[1];
    int row_stride;

    
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    
    if ((outfile = fopen(filename, "wb")) == NULL) {
        printf("Cannot open %s for writing JPEG\n", filename);
        jpeg_destroy_compress(&cinfo);
        return;
    }
    jpeg_stdio_dest(&cinfo, outfile);

    
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;        
    cinfo.in_color_space = JCS_RGB;     

    
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 75, TRUE);

    jpeg_start_compress(&cinfo, TRUE);

    
    row_stride = width * 3; 
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] = (JSAMPROW)&pixels[cinfo.next_scanline * row_stride];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

   
    jpeg_finish_compress(&cinfo);
    fclose(outfile);
    jpeg_destroy_compress(&cinfo);

    printf("Sucessfuly converted to %s.\n", filename);
}