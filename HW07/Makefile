all: main

main: main.o image.o
	g++ -o main main.o image.o

main.o: main.cc image.h
	g++ -c -Wall -Werror main.cc

image.o: image.cc image.h
	g++ -c -Wall -Werror image.cc

