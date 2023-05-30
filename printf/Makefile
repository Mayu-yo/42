NAME 			=	libftprintf.a
SRCS 			=	ft_printf.c\
					ft_put.c\
					ft_basetoa.c
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rcs
RM				=	rm -f
OBJS			=	${SRCS:.c=.o}


.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
