NAME = push_swap

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
LIBFT = libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	make -C libft

# Dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

# Phony
.PHONY: all clean fclean re
