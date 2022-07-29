# My first makefile

all: sequenceSorter

sequenceSorter: main.o sorter.o
	gcc -o sequenceSorter main.o sorter.o -std=c11

main.o: main.c ./include/sorter.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic -std=c11

sorter.o: ./src/sorter.c ./include/sorter.h
	gcc -o sorter.o ./src/sorter.c -c -W -Wall -ansi -pedantic -std=c11

clean:
	rm -rf *.o *~ sequenceSorter