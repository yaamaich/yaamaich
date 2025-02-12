SERVER_NAME = server
CLIENT_NAME = client
S_SRC = server.c minitalk_utils.c
C_SRC = client.c minitalk_utils.c
S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: server client

server: $(S_OBJ)
	$(CC) -o $(SERVER_NAME) $(CFLAGS) $(S_SRC) 

client: $(C_OBJ)
	$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(C_SRC) 

clean:
	rm -rf $(S_OBJ) $(C_OBJ)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: clean