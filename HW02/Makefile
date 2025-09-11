all: main

mandelbrot_ASCII.o: mandelbrot_ASCII.c functions.h
	gcc -c -Wall -Werror mandelbrot_ASCII.c

main.o: main.c functions.h 
	gcc -c -Wall -Werror main.c

main: main.o mandelbrot_ASCII.o
	gcc -o main main.o mandelbrot_ASCII.o 
