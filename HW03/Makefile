all: main

mandelbrot_ascii_toFile.o: mandelbrot_ascii_toFile.c functions.h
	gcc -c -Wall -Werror mandelbrot_ascii_toFile.c

main.o: main.c functions.h 
	gcc -c -Wall -Werror main.c

main: main.o mandelbrot_ascii_toFile.o
	gcc -o main main.o mandelbrot_ascii_toFile.o 