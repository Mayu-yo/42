NAME 			=	libft.a
SRCS 			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
					ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c
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
