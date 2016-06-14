SRC = printf.c manage_funcs.c di_func.c o_func.c u_func.c x_func.c X_func.c c_func.c s_func.c p_func.c perc_func.c print_number.c print_char.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pedantic

NAME = libprintf.a

CC = gcc

AR = ar 

all : $(NAME)

$(OBJ) : $(SRC)
	$(CC) -c $(SRC)

$(NAME) : $(OBJ)
	$(AR) -rc $(NAME) $(OBJ)
	$(AR) -t $(NAME)
	ranlib $(NAME)

clean : 
	rm -f $(OBJ)

re : $(OBJ)