#include <iostream>
#include <stdio.h>
#include "FileStreamBuf.h"

FileStreamBuf::FileStreamBuf(FILE* f, int bufferSize){

    this->file = f;
    this->bufferSize = bufferSize;
    this->buffer = new unsigned char[bufferSize];
    setp((char*)this->buffer, (char*)this->buffer + bufferSize - 1);
    setg((char*)this->buffer, (char*)this->buffer + bufferSize - 1, (char*) this->buffer + bufferSize -1);
}

int FileStreamBuf::overflow(int c){
    
    size_t num = pptr() - pbase();

    if(fwrite(pbase(), 1, num, file) != num){

        return EOF;
    }

    pbump(-num);

    if(c != EOF){
        *pbase() = c;
    }

    setp((char*) buffer + 1, (char*) buffer + bufferSize - 1);

    return c;

}

int FileStreamBuf::sync(){

    size_t num = pptr() - pbase();

    if(fwrite(pbase(), 1, num, file) != num){

        return -1;
    }

    setp((char*) buffer, (char*)buffer + bufferSize -1);
    
    return 0;
}

int FileStreamBuf::underflow(){
    
    size_t numRead = fread(buffer, 1, bufferSize, file);

    if(numRead == 0){

        return EOF;
    }
    setg((char*) buffer, (char*) buffer, (char*) buffer + numRead);

    return (unsigned char) *gptr();
}

int FileStreamBuf::uflow(){

     size_t numRead = fread(buffer, 1, bufferSize, file);

    if(numRead == 0){

        return EOF;
    }
    setg((char*) buffer, (char*) buffer + 1, (char*) buffer + numRead);

    return (unsigned char) buffer[0];

}

FileStreamBuf::~FileStreamBuf(){

    delete[] this->buffer;
    fclose(this->file);

}