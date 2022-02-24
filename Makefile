NAME_CLIENT = client
NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c

SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Werror -Wall -Wextra

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
