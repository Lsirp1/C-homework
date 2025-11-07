all: main

main: main.o exercise.o book.o
	g++ -o main main.o exercise.o book.o

main.o: main.cc exercise.h book.h
	g++ -c -Wall -Werror main.cc

exercise.o: exercise.cc exercise.h
	g++ -c -Wall -Werror exercise.cc

book.o: book.cc book.h
	g++ -c -Wall -Werror book.cc