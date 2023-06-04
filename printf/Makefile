NAME 			=	libftprintf.a
SRCS 			=	ft_printf.c\
					ft_put_hex.c\
					ft_put_num.c\
					ft_put_str.c\
					ft_count.c\
					ft_put_address.c
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
