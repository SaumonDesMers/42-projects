NAME		= libftprintf.a

SRC_DIR		= .

SRC			= ${SRC_DIR}/ft_printf.c \
				${SRC_DIR}/ft_create_output.c \
				${SRC_DIR}/ft_parsing_tags.c \
				${SRC_DIR}/ft_read_arg.c \
				${SRC_DIR}/ft_printf_parsing.c \
				${SRC_DIR}/ft_manage_specifier.c \
				${SRC_DIR}/ft_manage_widht.c \

OBJ			= $(SRC:.c=.o)

SRC_DIR_LIBFT	= libft

SRC_LIBFT	= ${SRC_DIR_LIBFT}/ft_memset.c \
				${SRC_DIR_LIBFT}/ft_bzero.c \
				${SRC_DIR_LIBFT}/ft_memcpy.c \
				${SRC_DIR_LIBFT}/ft_memccpy.c \
				${SRC_DIR_LIBFT}/ft_memmove.c \
				${SRC_DIR_LIBFT}/ft_memchr.c \
				${SRC_DIR_LIBFT}/ft_memcmp.c \
				${SRC_DIR_LIBFT}/ft_strlen.c \
				${SRC_DIR_LIBFT}/ft_isalpha.c \
				${SRC_DIR_LIBFT}/ft_isdigit.c \
				${SRC_DIR_LIBFT}/ft_isalnum.c \
				${SRC_DIR_LIBFT}/ft_isascii.c \
				${SRC_DIR_LIBFT}/ft_isprint.c \
				${SRC_DIR_LIBFT}/ft_toupper.c \
				${SRC_DIR_LIBFT}/ft_tolower.c \
				${SRC_DIR_LIBFT}/ft_strchr.c \
				${SRC_DIR_LIBFT}/ft_strrchr.c \
				${SRC_DIR_LIBFT}/ft_strncmp.c \
				${SRC_DIR_LIBFT}/ft_strlcpy.c \
				${SRC_DIR_LIBFT}/ft_strlcat.c \
				${SRC_DIR_LIBFT}/ft_strnstr.c \
				${SRC_DIR_LIBFT}/ft_atoi.c \
				${SRC_DIR_LIBFT}/ft_calloc.c \
				${SRC_DIR_LIBFT}/ft_strdup.c \
				${SRC_DIR_LIBFT}/ft_substr.c \
				${SRC_DIR_LIBFT}/ft_strjoin.c \
				${SRC_DIR_LIBFT}/ft_strtrim.c \
				${SRC_DIR_LIBFT}/ft_split.c \
				${SRC_DIR_LIBFT}/ft_itoa.c \
				${SRC_DIR_LIBFT}/ft_strmapi.c \
				${SRC_DIR_LIBFT}/ft_putchar_fd.c \
				${SRC_DIR_LIBFT}/ft_putnbr_fd.c \
				${SRC_DIR_LIBFT}/ft_putstr_fd.c \
				${SRC_DIR_LIBFT}/ft_putendl_fd.c \
				${SRC_DIR_LIBFT}/ft_lstnew.c \
				${SRC_DIR_LIBFT}/ft_lstadd_front.c \
				${SRC_DIR_LIBFT}/ft_lstsize.c \
				${SRC_DIR_LIBFT}/ft_lstlast.c \
				${SRC_DIR_LIBFT}/ft_lstadd_back.c \
				${SRC_DIR_LIBFT}/ft_lstdelone.c \
				${SRC_DIR_LIBFT}/ft_lstclear.c \
				${SRC_DIR_LIBFT}/ft_lstiter.c \
				${SRC_DIR_LIBFT}/ft_lstmap.c

OBJ_LIBFT		= $(SRC_LIBFT:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${OBJ_LIBFT}
			${AR} $@ $^

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re