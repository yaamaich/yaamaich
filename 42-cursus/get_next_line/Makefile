SRC = get_next_line.c get_next_line_utils.c 
SRCS = get_next_line_utils_bonus.c get_next_line_bonus.c

OBJ = $(SRC:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = get_next_line.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJS)

fclean: clean
	$(RM) $(NAME)	

re: fclean all

.PHONY: all clean fclean re bonus
