CC 		= 	gcc
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic `sdl2-config --cflags`

_SRC 	= 	main.c \
			init_instance.c \
			render_bg.c \
			poll_events.c \
			init_maze.c \
			print_mem.c \
			horz_intersect.c \
			vert_intersect.c \
			wall_check.c \
			dist_2wall.c \
			comp_dist.c \
			draw_wall.c \
			kill_maze.c

SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ 	= 	$(_SRC:.c=.o)
OBJ 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS 	= 	maze.h
DEPS 	= 	$(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR 	= 	./include
SDIR 	= 	./src
ODIR 	= 	./obj
EXEC 	= 	dorenstein
LINKS 	= 	-lm `sdl2-config --libs`

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm -f $(EXEC) $(OBJ)

re: $(OBJ)
