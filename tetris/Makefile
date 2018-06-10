##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

NAME	= tetris

CC	= gcc -g

RM	= rm -f

SRCS	=	./src/main.c			\
		./src/help.c			\
		./src/utils_struct.c		\
		./src/struct_parsing.c		\
		./src/get_next_line.c		\
		./src/arg_parsing.c		\
		./src/my_getnbr_comma.c		\
		./src/print_tetriminos.c	\
		./src/parse_struct.c		\
		./src/my_sort_word_array.c	\
		./src/get_term_in_env.c		\
		./src/good_name_pieces.c	\
		./src/debug_mode.c		\
		./src/is_error.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

LIB	= -L ./lib/ -lmy -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my/
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

tests_run:
	make -C ./tests/
	./tests/units

clean:
	make clean -C ./lib/my/
	make clean -C ./tests/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) ./tests/units
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
