GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OBJECTS = main.o print_char.o

all: 0-print_content

0-print_content : main.o print_char.o
	gcc $(CFLAGS) -o 0-print_content main.o print_char.o

main.o : main.c 
	gcc $(CFLAGS) -c main.c

print_char.o : print_char.c
	gcc $(CFLAGS) -c print_char.c

clean: 
	rm 0-print_content main.o print_char.o