# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
       libft/ft_calloc.c \
       ft_rev_rotate.c \
       ft_freelst.c \
	   ft_push.c \
	   check.c \
	   ft_rotate.c \
	   ft_swap.c  # لا تترك "\" في آخر سطر إذا لم يكن هناك ملف بعده

OBJS = $(SRCS:.c=.o)

# Add other source files here
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony
.PHONY: all clean fclean re

$(LIBFT):
	make -C libft



clean:
	rm -f $(OBJS)
	make -C libft clean

fclean:	clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

# Dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony
.PHONY: all clean fclean re
