NAME 			=	push_swap
SRCS 			=	main.c\
					ft_arg_check.c\
					ft_sort.c ft_sort_five_or_less.c\
					ft_swap.c ft_rotate.c ft_push.c ft_reverse_rotate.c\
					ft_list.c ft_assign_index.c\
					ft_atoi.c ft_isdigit.c ft_strlen.c ft_split.c\
					ft_putendl_fd.c ft_putstr_fd.c

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rc
RM				=	rm -f
OBJS			=	${SRCS:.c=.o}


NAME_A = push_swap.a
${NAME_A}: ${OBJS}
	${LIBC} ${NAME_A} ${OBJS}
a: ${NAME_A}



.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} ../libft/libft.a

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS:.c=.o}

fclean: clean
	${RM} ${NAME}

re: fclean all
