SRC		=	ft_bzero.c ft_isalnum.c ft_isalpha.c \
			ft_isdigit.c ft_isprint.c ft_memcpy.c \
			ft_memset.c ft_strlen.c ft_isascii.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_memchr.c ft_memcmp.c \
			ft_strncmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

SRC_LIB	 =	${addprefix libft/, ${SRC}}

SRC_PRNT =	ft_printf.c ft_strtilchr.c handle_char.c ft_initializers.c \
			ft_isformat.c handle_n.c handle_str.c ft_strmemjoin.c \
			handle_unsigned.c handle_ph.c handle_ptr.c ft_itohex.c \
			ft_ptoi.c ft_uitoa.c ft_strtoupper.c handle_hex.c \
			ft_uitohex.c check_flags.c

H_SRC	=	./libft/libft.h ft_printf.h

OBJS	=	${SRC_LIB:.c=.o} ${SRC_PRNT:.c=.o}

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
			cc ${FLAGS} -c $< -o ${<:.c=.o} 

$(NAME):	${OBJS} ${H_SRC}
			ar -rcs $@ $^

all: 		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re