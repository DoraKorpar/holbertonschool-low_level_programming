CFLAGS = -Wall -Wextra -Werror -pedantic
OBJECTS = 0-main.o 01-shell_loop.o 10-print_char.o 02-built_in_func.o 11-string_compare.o 06-print_env.o 07-exit_shell.o 03-program_exec.o 04-find_path.o 05-where_program.o 12-string_concat.o
LIB = libshell.a

all : simple-shell

simple-shell : $(OBJECTS) $(LIB)
	gcc $(CFLAGS) -o simple-shell $(OBJECTS) $(LIB)

0-main.o : 0-main.c
	gcc $(CFLAGS) -c 0-main.c

01-shell_loop.o : 01-shell_loop.c
	gcc $(CFLAGS) -c 01-shell_loop.c

10-print_char.o : 10-print_char.c
	gcc $(CFLAGS) -c 10-print_char.c

02-built_in_func.o : 02-built_in_func.c
	gcc $(CFLAGS) -c 02-built_in_func.c

11-string_compare.o : 11-string_compare.c
	gcc $(CFLAGS) -c 11-string_compare.c

06-print_env.o : 06-print_env.c
	gcc $(CFLAGS) -c 06-print_env.c

07-exit_shell.o : 07-exit_shell.c
	gcc $(CFLAGS) -c 07-exit_shell.c

03-program_exec.o : 03-program_exec.c
	gcc $(CFLAGS) -c 03-program_exec.c

04-find_path.o : 04-find_path.c
	gcc $(CFLAGS) -c 04-find_path.c

05-where_program.o : 05-where_program.c
	gcc $(CFLAGS) -c 05-where_program.c

12-string_concat.o : 12-string_concat.c
	gcc $(CFLAGS) -c 12-string_concat.c

clean :
	rm simple-shell $(OBJECTS)