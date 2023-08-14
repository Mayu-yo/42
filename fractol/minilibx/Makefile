#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NOM)

$(NOM):	$(OBJ)
	@ ar -r $(NOM) $(OBJ)
	@ ranlib $(NOM)
	@ printf "$(_SUCCESS) minilibx: ${NOM} was created.\n"

clean:
	@ rm -f $(NOM) $(OBJ) *~
	@ rm -f mlx_app
	@ printf "$(_INFO) minilibx: Removed all object files\n"

re: clean all
