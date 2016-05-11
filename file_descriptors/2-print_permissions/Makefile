CFLAGS = -Wall -Werror -Wextra -pedantic

all : 2-print_permissions

2-print_permissions : main.o print_char.o
	gcc $(CFLAGS) -o 2-print_permissions main.o print_char.o

main.o : main.c
	gcc $(CFLAGS) -c main.c

print_char.o : print_char.c
	gcc $(CFLAGS) -c print_char.c

clear :
	rm 1-copy_content main.o print_char.o