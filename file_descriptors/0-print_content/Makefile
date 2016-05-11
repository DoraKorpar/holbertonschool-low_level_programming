GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OBJECTS = main.o

all: 0-print_content

0-print_content : main.o
	gcc $(CFLAGS) -o 0-print_content main.o

main.o : main.c 
	gcc $(CFLAGS) -c main.c

clean: 
	rm 0-print_content main.o