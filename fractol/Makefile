
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
SRCS			=	mandelbrot.c handle.c
OBJS			=	${SRCS:.c=.o}
INC				=	-I$(LIBFT_DIR) -I$(MLX_INC)

	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror -g
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

# %.o: %.c
# 	@ $(CC) $(CFLAG) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@ $(CC) $(CFLAG) $(OBJS) -L$(MLX) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@ $(MAKE) -C $(MLX)

clean:
	@ $(RM) $(OBJS)
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ $(MAKE) clean -C $(MLX)
	@ printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re

