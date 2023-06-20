NAME 			=	push_swap.a
SRCS 			=	main.c\
					ft_sort.c\
					ft_swap.c ft_rotate.c ft_push.c ft_reverse_rotate.c\
					ft_list.c\
					ft_atoi.c ft_isdigit.c ft_strlen.c\
					ft_putendl_fd.c ft_putstr_fd.c

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rc
RM				=	rm -f
OBJS			=	${SRCS:.c=.o}



.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS:.c=.o}

fclean: clean
	${RM} ${NAME}

re: fclean all
