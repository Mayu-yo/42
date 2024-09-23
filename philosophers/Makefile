
	# Library Name #
NAME		= philo

	# Compiling Variables #
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f

# CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address

SRC			= main.c \
				src/action.c \
				src/init.c \
				src/thread.c \
				src/utils.c \
				src/time.c

SRCS		= $(SRC:%.c=%.o)
OBJS = $(SRC:.c=.o)

INC_DIR	= includes
INC			= philo.h
INCS		= $(addprefix $(INC_DIR)/, $(INC))


CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all : $(NAME)

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(OBJ_DIR)
	cc -c $< -o $@

$(NAME) : $(OBJS)
	@ echo ""
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@ echo "$(CHECK) $(BLUE)Compiling Philosophers... $(RESET)"

clean:
	@ $(RM) -r ./src/*.o ./*.o
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r ./src/*.o ./*.o
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files and $(NAME).$(RESET)\n"

re: fclean all

.PHONY : all clean fclean re debug thread