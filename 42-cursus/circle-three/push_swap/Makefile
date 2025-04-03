# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
    	ft_rev_rotate.c \
    	ft_freelst.c \
    	ft_push.c \
    	sortcheck.c \
    	ft_rotate.c \
    	ft_swap.c  \
		init.c \
		index.c \
		sort_algo.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
LIBFTPRINTF = printf/libftprintf.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBFTPRINTF)

$(LIBFT):
	make -C libft

$(LIBFTPRINTF):
	make -C printf

# Dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

# Phony
.PHONY: all clean fclean re
