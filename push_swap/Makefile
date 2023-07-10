NAME 			=	push_swap
SRCS 			=	main.c\
					ft_arg_check.c\
					ft_sort.c ft_sort_five_or_less.c\
					ft_swap.c ft_rotate.c ft_push.c ft_reverse_rotate.c\
					ft_list.c ft_assign_index.c
LIBFT			=	./libft/libft.a
LIBFT_DIR		=	./libft

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
OBJS			=	${SRCS:.c=.o}

# .c.o:
# 	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

all: ${NAME}

clean:
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re