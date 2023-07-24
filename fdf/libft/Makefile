
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
					ft_substr.c ft_split.c\
					get_next_line_bonus.c
INC				=	-I$(PRINTF_DIR)

	# printf Variables #
PRINTF_DIR		=	./printf
PRINTF			=	./printf/libftprintf.a

# 	# get_next_line Variables #
# GNL_DIR			=	./get_next_line
# GNL				=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
# GNL_O			=	$(GNL:.c=.o)

	# Compiling Variables #
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBC			=	ar -rc
RM				=	rm -f
OBJS			=	$(SRCS:.c=.o)


	# Colors #
GREEN			=	\e[38;5;118m
YELLOW			=	\e[38;5;226m
RESET			=	\e[0m
_SUCCESS		=	[$(GREEN)SUCCESS$(RESET)]
_INFO			=	[$(YELLOW)INFO$(RESET)]



.c.o:
#	$(CC) $(CFLAGS) -c $< -o $@
	@ $(CC) $(CFLAG) -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(PRINTF)
	@ $(LIBC) $(NAME) $(OBJS) $(PRINTF)
	@printf "$(_SUCCESS) $(NAME) was created.\n"

$(PRINTF):
	@ $(MAKE) -C $(PRINTF_DIR)


all: $(NAME)

clean:
	@ $(RM) $(OBJS)
	@ $(MAKE) clean -C $(PRINTF_DIR)
	@printf "$(_INFO) libft: object files were deleted.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@printf "$(_INFO) $(NAME) was deleted.\n"

re: fclean all

