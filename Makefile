NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c \
	  parse.c \
	  sanitise.c \
	  validate.c \
	  swap.c \
	  rotate.c \
	  rrotate.c \
	  push.c \
	  libft.c \
	  sort.c \
	  bits.c \
	  ft_atoi.c \
	  ft_calloc.c

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c push_swap.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re