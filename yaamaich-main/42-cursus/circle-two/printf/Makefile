SRC = ft_putchar.c ft_putnbr.c ft_putstr.c ft_printf.c ft_putunsnbr.c ft_putptr.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean 
	rm -rf ${NAME}

re: fclean all

.PHONY : clean fclean all re 