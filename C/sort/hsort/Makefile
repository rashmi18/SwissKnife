GCC=gcc
FLAGS=-DTEST

all:
	${GCC} ${FLAGS} -c main.c 
	${GCC} ${FLAGS} -c hsort.c
	${GCC} ${FLAGS} main.o hsort.o -o hsort -lm

clean:
	rm -f *.o
