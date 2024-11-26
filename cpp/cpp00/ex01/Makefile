
NAME	= PhoneBook
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

OBJDIR = .objFiles

SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean re

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) was created.\n"

clean:
	@$(RM) $(OBJS)
	@ printf "$(_INFO) object files removed.\n"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@ printf "$(_INFO) $(NAME) removed.\n"

re: clean all