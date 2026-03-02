SRC = setup_config.c philo_main.c philo_routine.c utils_helper.c check_death.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
OBG = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

%.o:%.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBG)

fclean : clean
	@rm -rf $(NAME)

re : fclean all