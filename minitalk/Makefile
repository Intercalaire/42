CC = clang
CFLAGS = -Wall -Wextra -Werror -g
Libft_PATH = Libft
Libft_FILE = Libft/Libft.a
SERVER = server
CLIENT = client
SERVER_SRC = server.c
CLIENT_SRC = client.c

all: $(SERVER) $(CLIENT)


$(SERVER): $(SERVER_SRC)
	make -C $(Libft_PATH)
	$(CC) $(CFLAGS) -o $@ $^ $(Libft_FILE)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(Libft_FILE)

clean:
	make clean -C $(Libft_PATH)
	rm -f $(SERVER) $(CLIENT)

fclean: clean
	make fclean -C $(Libft_PATH)
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
