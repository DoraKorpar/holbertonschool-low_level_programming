CFLAGS = -Wall -Wextra -Werror -pedantic
OBJECTS = main.o shell_loop.o print_char.o get_func.o string_compare.o print_env.o
LIB = libshell.a

all : simple-shell

simple-shell : $(OBJECTS) $(LIB)
	gcc $(CFLAGS) -o simple-shell $(OBJECTS) $(LIB)

main.o : main.c
	gcc $(CFLAGS) -c main.c

shell_loop.o : shell_loop.c
	gcc $(CFLAGS) -c shell_loop.c

print_char.o : print_char.c
	gcc $(CFLAGS) -c print_char.c

get_func.o : get_func.c
	gcc $(CFLAGS) -c get_func.c

string_compare.o : string_compare.c
	gcc $(CFLAGS) -c string_compare.c

print_env.o : print_env.c
	gcc $(CFLAGS) -c print_env.c

clean :
	rm simple-shell $(OBJECTS)