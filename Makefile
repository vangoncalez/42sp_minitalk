# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 21:28:46 by vaferrei          #+#    #+#              #
#    Updated: 2022/01/18 03:21:10 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CLIENT 				= client
SERVER 				= server
CLIENT_BONUS 		= client_bonus
SERVER_BONUS 		= server_bonus
LIBFT       		= ./libft/libft.a
LFTDIR				= ./libft
DIR 				= ./src/
DIR_BONUS 			= ./src_bonus/

SRCS_CLIENT			= 	$(DIR)main_client.c
SRCS_SERVER			= 	$(DIR)main_server.c
SRCS_CLIENT_BONUS	= 	$(DIR_BONUS)main_client_bonus.c
SRCS_SERVER_BONUS	= 	$(DIR_BONUS)main_server_bonus.c


OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)
OBJS_SERVER=$(SRCS_SERVER:.c=.o)

OBJS_CLIENT_BONUS=$(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS=$(SRCS_SERVER_BONUS:.c=.o)


CFLAGS		= -Wall -Wextra -Werror
CC 			= clang

RM =rm -f

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) -L $(LFTDIR) -lft

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) -L $(LFTDIR) -lft

$(LIBFT):
	$(MAKE) -C $(LFTDIR)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJS_CLIENT_BONUS) -L $(LFTDIR) -lft

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_SERVER_BONUS) -L $(LFTDIR) -lft


re: fclean all

rebonus: fclean bonus

clean:
	make clean -C $(LFTDIR)
	$(RM) -rf $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	make fclean -C $(LFTDIR)
	$(RM) -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

.PHONY: clean fclean re rebonus all bonus
