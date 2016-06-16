SRC = main.c cross.c top_cross.c bottom_cross.c stoi.c print_char.c middle_space.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pedantic

CC = gcc

OUT = cross

all: $(OUT)

$(OUT) : $(SRC)
	$(CC) -o $(OUT) $(SRC)

clean :
	rm -f $(OUT)

re : $(OBJ)