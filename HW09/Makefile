all: main

main: main.o FileStreamBuf.o
	g++ -o main main.o FileStreamBuf.o

main.o: main.cc FileStreamBuf.h
	g++ -c -Werror -Wall main.cc

FileStreamBuf.o: FileStreamBuf.cc FileStreamBuf.h
	g++ -c -Werror -Wall FileStreamBuf.cc