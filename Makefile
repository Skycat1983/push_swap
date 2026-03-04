NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -g


SRC = main.c \
	  parse.c \
	  sanitise.c \
	  validate.c \
	  swap.c \
	  swap_log.c \
	  rotate.c \
	  rotate_log.c \
	  rrotate.c \
	  rrotate_log.c \
	  push.c \
	  push_log.c \
	  helpers.c \
	  libft.c \
	  sort.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
