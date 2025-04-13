SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean 
	rm -rf ${NAME}

re: fclean all

.PHONY : clean fclean all re 