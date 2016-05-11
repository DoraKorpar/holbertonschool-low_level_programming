CFLAGS = -Wall -Werror -Wextra -pedantic

all : 1-copy_content

1-copy_content : main.o
	gcc $(CFLAGS) -o 1-copy_content main.o

main.o : main.c
	gcc $(CFLAGS) -c main.c

clear :
	rm 1-copy_content main.o