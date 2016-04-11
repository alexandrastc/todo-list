CC=gcc
CFLAGS= -c -std=c99 -Wall

all: todo-list

todo-list: main.o list.o display.o
	$(CC) main.o list.o display.o -o todo-list

main.o: main.c
	$(CC) $(CFLAGS) main.c 

list.o: list.c
	$(CC) $(CFLAGS) list.c

display.o : display.c
	$(CC) $(CFLAGS) display.c

clean:
	rm -rf *o

