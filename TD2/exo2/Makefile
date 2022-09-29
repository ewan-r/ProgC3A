all: mem

clean:
		rm -f mem mem.o common.o

mem: mem.o common.o
		gcc common.o mem.o -o mem

mem.o: mem.c common.h
		gcc -c mem.c -Wall

common.o: common.c common.h
		gcc -c common.c -Wall