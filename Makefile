CC=gcc
CFLAGS = -c -std=c99 -Wall

all: todo-list

todo-list: main.o 
  $(CC) main.o -o todo-list

main.o: main.c
  $(CC) $(CFLAGS) main.c 

clean:
  rm -rf *o

