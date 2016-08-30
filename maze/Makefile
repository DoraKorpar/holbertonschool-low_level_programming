CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main.c poll_events.c init_instance.c
OBJ = $(SRC:.c=.o)
EXEC = dorenstein
SDL = `sdl2-config --cflags --libs`

all : $(EXEC)

$(EXEC) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(SDL)

.PHONY : clean

clean :
	rm -f $(EXEC)

re: $(OBJ)
