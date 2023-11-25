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

all: client server

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lftprintf

$(CLIENT_OBJ): $(CLIENT_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(SERVER_OBJ): $(SERVER_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
