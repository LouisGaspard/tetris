##
## EPITECH PROJECT, 2018
## unitair
## File description:
## unitair
##

SRC_DIR		=	$(realpath ../src)

SRC		=	$(SRC_DIR)/arg_parsing.c		\
			$(SRC_DIR)/debug_mode.c			\
			$(SRC_DIR)/get_next_line.c		\
			$(SRC_DIR)/get_term_in_env.c		\
			$(SRC_DIR)/good_name_pieces.c		\
			$(SRC_DIR)/help.c			\
			$(SRC_DIR)/is_error.c			\
			$(SRC_DIR)/my_getnbr_comma.c		\
			$(SRC_DIR)/my_sort_word_array.c		\
			$(SRC_DIR)/parse_struct.c		\
			$(SRC_DIR)/print_tetriminos.c		\
			$(SRC_DIR)/struct_parsing.c		\
			$(SRC_DIR)/utils_struct.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/test_arg_parsing.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra

CFLAGS		+=	-I ../include

LDFLAGS		=	-L ../lib/my/ -lmy -lcriterion -lgcov -lncurses

NAME		=	units

CC		=	gcc --coverage

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ../lib/my/
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		$(MAKE) clean -C ../lib/my/
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_UT_DIR)/*.g*

fclean:		clean
		$(MAKE) fclean -C ../lib/my/
		rm -f $(NAME)

re:		fclean all
