# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 19:42:14 by mayyamad          #+#    #+#              #
#    Updated: 2023/07/20 20:16:45 by mayyamad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
# NAME	=
CLIENT	=	client
SERVER	=	server

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
PRINTF		=	./printf/libftprintf.a
PRINTF_DIR	=	./printf

	# Mandatory Variables #
SRC_C	=	client.c
SRC_S	=	server.c
INC		=	-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

	# Compiling Variables #
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]


all: $(SERVER) $(CLIENT)

# $(NAME): all

$(SERVER): $(LIBFT) $(PRINTF)
	@ $(CC)  $(CFLAG) $(SRC_S) $(LIBFT) $(PRINTF) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(LIBFT) $(PRINTF)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(PRINTF) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"


$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@ $(MAKE) -C $(PRINTF_DIR)

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re