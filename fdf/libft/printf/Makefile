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



	# Colors #
GREEN			=	\e[38;5;118m
YELLOW			=	\e[38;5;226m
RESET			=	\e[0m
_SUCCESS		=	[$(GREEN)SUCCESS$(RESET)]
_INFO			=	[$(YELLOW)INFO$(RESET)]



.c.o:
	@ ${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@ ${LIBC} ${NAME} ${OBJS}
	@printf "$(_SUCCESS) $(NAME) was created.\n"
	
all: ${NAME}

clean:
	@ ${RM} ${OBJS} ${BONUS_OBJS}
	@printf "$(_INFO) printf: object files were deleted.\n"

fclean: clean
	@ ${RM} ${NAME}
	@printf "$(_INFO) $(NAME) was deleted.\n"

re: fclean all
