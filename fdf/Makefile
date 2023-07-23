# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 19:49:06 by mayyamad          #+#    #+#              #
#    Updated: 2023/07/23 17:30:36 by mayyamad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
NAME		=	fdf

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
GNL			=	./gnl/get_next_line_bonus.c ./gnl/get_next_line_bonus_util.c
GNL_DIR		=	./gnl

	# Mandatory Variables #
# SRC_C	=	client.c
# SRC_S	=	server.c
# INC		=	-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
# INC				=	-I. -I$(GNL_DIR)
SRCS			=	main.c readmap.c\
					./gnl/get_next_line_bonus.c ./gnl/get_next_line_bonus_util.c
OBJS			=	${SRCS:.c=.o}

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


all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(SERVER): $(LIBFT) $(PRINTF)
# 	@ $(CC)  $(CFLAG) $(SRC_S) $(LIBFT) $(PRINTF) $(INC) -o $(SERVER)
# 	@printf "$(_SUCCESS) server ready.\n"

# $(CLIENT): $(LIBFT) $(PRINTF)
# 	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(PRINTF) $(INC) -o $(CLIENT)
# 	@printf "$(_SUCCESS) client ready.\n"


# $(LIBFT):
# 	@ $(MAKE) -C $(LIBFT_DIR)

# $(GNL):
# 	@ $(MAKE) -C $(GNL_DIR)

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