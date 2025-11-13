#include <iostream>
#include<stdio.h>

class FileStreamBuf : public std::streambuf {

   private:

   FILE* file;
   int bufferSize;
   unsigned char* buffer; 

   public: 

   FileStreamBuf(FILE* f, int bufferSize);
   virtual int overflow(int c) override;
   virtual int sync() override;
   virtual int underflow() override;
   virtual int uflow() override;
   virtual ~FileStreamBuf();


};
