
NAME	= megaphone
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

SRCS = megaphone
OBJ			= $(SRCS:=.o)

.PHONY: all clean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) was created.\n"

clean:
	@$(RM) $(OBJ)
	@ printf "$(_INFO) object files removed.\n"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@ printf "$(_INFO) $(NAME) removed.\n"

re: clean all