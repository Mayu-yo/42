NAME	= Animal
	
CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

SRCS = $(wildcard srcs/*.cpp)
HEADERS = $(wildcard includes/*.hpp)
OBJDIR = objs
OBJS = $(patsubst srcs/%.cpp, objs/%.o, $(SRCS)) #ここ後で変更かも
INC = -I./includes/


all : $(NAME)

$(NAME): $(OBJS)
	@ $(CXX) $(CXXFLAGS) -o $@ $^
	@printf "$(_SUCCESS) $(NAME) was created.\n"

objs/%.o: srcs/%.cpp
	@ mkdir -p objs
	@ $(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

clean :
	@ $(RM) $(OBJDIR)
	@ printf "$(_INFO) object files removed.\n"

fclean : clean
	@ $(RM) $(NAME)
	@ printf "$(_INFO) object files removed.\n"


re : fclean all

.PHONY : all clean fclean re