NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC =  push_swap.c free.c ft_atoi.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c index.c init.c push.c rev_rotate.c rotate.c sort_algo.c swap.c utils.c small_elements.c ft_strncmp.c
SRC_BONUS = checker_bonus.c free_bonus.c ft_atoi_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_split_bonus.c ft_strncmp_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c init_bonus.c push_bonus.c rev_rotate_bonus.c rotate_bonus.c swap_bonus.c utils_bonus.c 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)
	touch bonus
	
$(OBJ):%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS):%.o:%.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	rm -f bonus

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean