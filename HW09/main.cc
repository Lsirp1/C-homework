#include <iostream>
#include "FileStreamBuf.h"
#include <ostream>

int main(){

    FILE* file = fopen("test.txt", "w");
    if(!file) {
        std::cerr<<"Failed to open file."<<std::endl;
        return 1;
    }
    FileStreamBuf buf(file, 4);
    std::ostream out(&buf);

    out << "yo"<<std::endl;
    buf.sync();
    fclose(file);

    FILE* filein = fopen("test.txt", "r");
    FileStreamBuf inBuf(filein, 4);
    std::istream in(&inBuf);
    std::string line;
    std::getline(in, line);
    std::cout<<"Read: "<<line<<std::endl;

    return 0;
}