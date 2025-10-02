all: main

write_mandebrot_image.o: write_mandelbrot_image.c functions.h
	gcc -c -Wall -Werror write_mandelbrot_image.c

mandelbrot_image.o: mandelbrot_image.c functions.h
	gcc -c -Wall -Werror mandelbrot_image.c

main.o: main.c functions.h
	gcc -c -Wall -Werror main.c

main: main.o mandelbrot_image.o write_mandelbrot_image.o
	gcc -o main main.o mandelbrot_image.o write_mandelbrot_image.o	
