CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include/ft_printf
LIB_DIR = include/ft_printf
LIBFTPRINTF = libftprintf.a

CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o

CLIENT_BONUS_SRC = $(SRC_DIR)/client_bonus.c
SERVER_BONUS_SRC = $(SRC_DIR)/server_bonus.c
CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o
SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o

all: client server

bonus: client_bonus server_bonus

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

client_bonus: $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

server_bonus: $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

$(CLIENT_OBJ): $(CLIENT_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(SERVER_OBJ): $(SERVER_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(CLIENT_BONUS_OBJ): $(CLIENT_BONUS_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(SERVER_BONUS_OBJ): $(SERVER_BONUS_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
