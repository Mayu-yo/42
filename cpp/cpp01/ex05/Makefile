
NAME	= Harl
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

SRCS = main Harl
HEADER		= Harl.hpp
OBJDIR = .objFiles
OBJ			= $(addprefix $(OBJDIR)/, $(SRCS:=.o))

.PHONY: all clean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ $(CC) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) was created.\n"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@ printf "$(_INFO) object files removed.\n"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJDIR)
	@ printf "$(_INFO) $(NAME) removed.\n"

re: clean all