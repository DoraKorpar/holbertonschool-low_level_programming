CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

_SRC = main.c poll_events.c init_instance.c render_bg.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ = $(_SRC:.c=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = header.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR = ./include
SDIR = ./src
ODIR = ./obj
EXEC = dorenstein
SDL = `sdl2-config --cflags --libs`

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(SDL)

.PHONY : clean

clean :
	rm -f $(EXEC) $(OBJ)

re: $(OBJ)
