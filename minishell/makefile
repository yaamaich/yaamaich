# Colors
BLUE  = \033[34m
RESET = \033[0m
UNDER = \033[4m

BY = By: $(UNDER)$(BLUE)yaamaich®️$(RESET) && $(UNDER)$(BLUE)albelaiz®️$(RESET)

# Big banner in BLUE
MINI = "$(BLUE)\
+==================================================+\\n\
||      __  __ _       _     _          _ _       ||\\n\
||     |  \\/  (_)_ __ (_)___| |__   ___| | |      ||\\n\
||     | |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |      ||\\n\
||     | |  | | | | | | \\__ \\ | | |  __/ | |      ||\\n\
||     |_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|      ||\\n\
+==================================================+\\n\
$(RESET)====>>                    $(BY)"



CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
READLINE_INC = -I$(HOME)/goinfre/homebrew/opt/readline/include
READLINE_LIB = -L$(HOME)/goinfre/homebrew/opt/readline/lib -lreadline
LIBFT = ./ft_libft/libft.a
NAME = minishell

SRCS =	builts0.c		ft_env.c			ft_pwd.c	mk_token_tools.c \
		check_sintax.c	ft_envariements.c	ft_setenv.c mk_token_tools_2.c\
		execute.c		ft_exit.c			ft_unset.c	parc_token.c\
		execute_tools.c ft_export.c			main.c		parc_token_tools.c\
		f_norminette.c	ft_get_env.c		signals.c	mk_token.c\
		ft_cd.c			ft_give_env.c		ft_echo.c	f_norminette2.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C ./ft_libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_LIB) $(READLINE_INC) -o $(NAME)
	@echo $(MINI)


%.o: %.c minishell.h
	@$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C ./ft_libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./ft_libft fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT)