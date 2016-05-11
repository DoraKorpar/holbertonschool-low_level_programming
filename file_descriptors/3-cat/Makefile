GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OBJECTS = main.o

all: 3-cat

3-cat : main.o
	gcc $(CFLAGS) -o 3-cat main.o

main.o : main.c 
	gcc $(CFLAGS) -c main.c

clean: 
	rm 3-cat main.o