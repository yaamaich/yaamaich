NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I MLX42/include/MLX42 -I libft/include 

LFLAGS = -L"/goinfre/yaamaich/homebrew/opt/glfw/lib" -lglfw

MLX = libmlx42.a

LIBFT = libft/libft.a 

SRC = so_long.c draw.c character.c walls_floors_and_move_count.c parse_map.c validate_map.c map_utils.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MLX) $(LFLAGS) -o $(NAME)

$(MLX):
	make -C MLX42/build

$(LIBFT):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re