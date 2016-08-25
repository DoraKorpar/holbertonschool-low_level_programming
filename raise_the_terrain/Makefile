CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main_practice.c init_instance.c poll_events.c draw_grid_alt.c draw_lines2.c add_alt.c
OBJ = $(SRC:.c=.o)
EXEC = sdl_practice
SDL = `sdl2-config --cflags --libs`

all : $(EXEC)

$(EXEC) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(SDL)
clean :
	rm -f $(EXEC)

re: $(OBJ)
