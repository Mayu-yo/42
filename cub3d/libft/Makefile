
	# Library Name #
NAME 			=	libft.a

	# Mandatory Variables #
SRCS 			=	ft_toupper.c ft_tolower.c\
					ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
					ft_strlen.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c\
					ft_strncmp.c ft_strdup.c ft_strjoin.c ft_strtrim.c\
					ft_strnstr.c ft_striteri.c ft_strmapi.c\
					ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
					ft_atoi.c ft_itoa.c\
					ft_calloc.c ft_bzero.c\
					ft_substr.c ft_split.c

	# Bonus Variables #
BONUS			=	ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstmap.c

	# Compiling Variables #
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rc
RM				=	rm -f

ifdef WITH_BONUS
SRCS		+=	${BONUS}
endif
OBJS			=	${SRCS:.c=.o}

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]


.c.o:
	@ ${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@ ${LIBC} ${NAME} ${OBJS}
	@ printf "$(_SUCCESS) libft: ${NAME} was created.\n"
	
all: ${NAME}

clean:
	@ ${RM} ${OBJS} ${BONUS:.c=.o}
	@ printf "$(_INFO) libft: Removed all object files\n"

fclean: clean
	@ ${RM} ${NAME}
	@ printf "${_INFO} libft: Removed the executables\n"

re: fclean all

bonus:
	make WITH_BONUS=1 ${NAME}
