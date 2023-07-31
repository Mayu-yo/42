
	# Library Name #
NAME		=	fdf

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

	# Mandatory Variables #
SRCS			=	main.c readmap.c
OBJS			=	${SRCS:.c=.o}
INC				=	-I$(LIBFT_DIR)

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
	$(CC) $(CFLAG) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)


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










# # Library Name #
# NAME		=	fdf

# # libft Variables #
# LIBFT		=	./libft/libft.a
# LIBFT_DIR	=	./libft

# # Minilibx Variables #
# MLX			=	./minilibx-linux
# MLX_LIB		=	$(MLX)/libmlx.a

# # Mandatory Variables #
# SRCS			=	main.c readmap.c
# OBJS			=	${SRCS:.c=.o}
# INC				=	-I$(LIBFT_DIR) -I$(MLX_INC)

# # Compiling Variables #
# CC			=	cc
# CFLAG		=	-Wall -Wextra -Werror
# RM			=	rm -f

# # Colors #
# GREEN		=	\e[38;5;118m
# YELLOW		=	\e[38;5;226m
# RESET		=	\e[0m
# _SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
# _INFO		=	[$(YELLOW)INFO$(RESET)]

# all: $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAG) $(INC) -c $< -o $@

# $(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
# 	$(CC) $(OBJS) -L$(MLX) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit -o $(NAME)

# $(LIBFT):
# 	@ $(MAKE) -C $(LIBFT_DIR)

# $(MLX_LIB):
# 	@ $(MAKE) -C $(MLX)

# clean:
# 	@ $(RM) $(OBJS)
# 	@ $(MAKE) clean -C $(LIBFT_DIR)
# 	@ $(MAKE) clean -C $(MLX)
# 	@ printf "$(_INFO) object files removed.\n"

# fclean: clean
# 	@ $(RM) $(NAME)
# 	@ $(MAKE) fclean -C $(LIBFT_DIR)
# 	@ printf "$(_INFO) $(NAME) removed.\n"

# re: fclean all

# .PHONY: all clean fclean re
