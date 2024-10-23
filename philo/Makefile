
	# Library Name #
NAME		= philo

	# Compiling Variables #
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f

# CFLAGS += -fsanitize=address
CFLAGS += -fsanitize=thread

	# Source Files #
SRCS_NAME		= main.c \
				action.c \
				init.c \
				thread.c \
				libft_utils.c \
				philo_utils.c \
				exit.c \
				time.c

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRCS		=	$(SRC:%.c=%.o)
OBJ_NAME	=	$(SRCS_NAME:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

INC			=	-I inc/

	# Colors #
CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all : $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(OBJ_DIR)
	cc -c $< -o $@

$(NAME) : $(OBJS)
	@ echo ""
	@ $(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)
	@ echo "$(CHECK) $(BLUE)Compiling Philosophers... $(RESET)"

clean:
	@ $(RM) -r $(OBJ_DIR)
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r $(OBJ_DIR)
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files and $(NAME).$(RESET)\n"

re: fclean all

.PHONY : all clean fclean re debug thread