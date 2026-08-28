NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft

LIBFT = libft/libft.a

SRC = trial/main.c \
      operations/moves1.c \
      operations/moves2.c \
      operations/moves3.c \
      operations/moves4.c \
      parsing/parsing_utils.c \
      parsing/parsing.c \
      parsing/stack_utils.c \
      algo/simple.c \
      algo/complex.c\
	  algo/heap.c\
	  algo/adaptive.c\
	  algo/selector.c\
	  algo/medium.c\
	  algo/medium_utils.c\
	  algo/bench.c\
	  algo/root.c\
	  algo/complex_help.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
