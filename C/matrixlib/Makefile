CC= gcc -std=c99
FLAGS= -Wall -Wextra -Wundef -Wpointer-arith -Wshadow -Wcast-align -Wstrict-prototypes -Waggregate-return

main: matrix.c
	$(CC) -o main.o main.c matrix.c

matrix: matrix.c matrix.h
	$(CC) -c matrix.c

make clean: 
	rm -rf *.o
