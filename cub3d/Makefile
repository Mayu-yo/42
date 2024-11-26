
	# Library Name #
NAME		=	cub3D

	# libft Variables #
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_DIR	=	./libft

	# GNL Variables #
GNL_DIR		=	./gnl

	# Minilibx Variables #
MLX			=	./minilibx
MLX_LIB		=	$(MLX)/liblmx.a
HEADERS		=	cub3d.h

	# Mandatory Variables #
SRCS			=	main.c \
					parse_cub.c \
					check_map.c \
					check_map_utils.c \
					utils.c \
					handle_mlx.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC				=	-I$(LIBFT_DIR) -I$(MLX)

	# Directories #
SRC_DIR			=	./src
OBJ_DIR			=	./objs

	# Compiling Variables #
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: mkdir $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
# @ $(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX) $(MLX_FLAGS) $(OBJS) -o $(NAME)
	@ gcc $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX) $(MLX_FLAGS) $(OBJS) -g -o $(NAME)
	@ printf "$(_SUCCESS) $(NAME) was created.\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $^

mkdir:
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/gnl

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
