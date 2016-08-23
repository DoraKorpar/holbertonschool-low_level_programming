CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJ = main_practice.c init_instance.c poll_events.c draw_grid_alt.c draw_lines2.c add_alt.c
EXEC = sdl_practice
LIB = -lSDL2

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(EXEC)

clean :
	rm $(EXEC)
