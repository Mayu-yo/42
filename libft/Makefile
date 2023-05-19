NAME 			=	libft.a
SRCS 			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c int ft_isprint.c \
					ft_strlen.c
INCS 			=	includes
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rcs
OBJS			=	${SRCS:.c=.o}



.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
