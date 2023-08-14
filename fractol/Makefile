
	# Library Name #
NAME		=	fractal

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

	# Minilibx Variables #
MLX			=	./minilibx
MLX_LIB		=	$(MLX)/liblmx.a
HEADERS		=	fractal.h

	# Mandatory Variables #
SRCS			=	main.c julia.c mandelbrot.c ft_atof.c handle.c
# OBJS			=	${SRCS:.c=.o}
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC				=	-I$(LIBFT_DIR) -I$(MLX_INC)
OBJ_DIR			=	./objects

	# Compiling Variables #
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror -g
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(OBJ_DIR)
	cc -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@ $(CC) $(CFLAG) $(OBJS) -L$(MLX) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit -o $(NAME)
	@ printf "$(_SUCCESS) $(NAME) was created.\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX)

clean:
	@ rm -rf $(OBJ_DIR)
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ $(MAKE) clean -C $(MLX)
	@ printf "$(_INFO) object files removed.\n"

fclean:
	@ rm -rf $(OBJ_DIR)
	@ $(RM) $(NAME)
	@ $(MAKE) clean -C $(MLX)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) object files removed.\n"
	@ printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re

