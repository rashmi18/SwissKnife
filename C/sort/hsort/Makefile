GCC=gcc
FLAGS=-DTEST
EXE=hsort

all:
	${GCC} ${FLAGS} -c main.c 
	${GCC} ${FLAGS} -c hsort.c
	${GCC} ${FLAGS} main.o hsort.o -o ${EXE} -lm

clean:
	rm -f *.o
	rm -f ${EXE}
