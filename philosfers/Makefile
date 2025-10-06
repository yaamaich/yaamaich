SRC = init.c main.c simulation.c tools.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
OBG = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

%.o:%.c philo
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBG)

fclean :
	@rm -rf $(NAME)

re : fclean all