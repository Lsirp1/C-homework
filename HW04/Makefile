all: read

readPPM.o: readPPM.c functions.h
	gcc -c -Wall -Werror readPPM.c

main.o: main.c functions.h
	gcc -c -Wall -Werror main.c

read: main.o readPPM.o
	gcc -o read main.o readPPM.o	