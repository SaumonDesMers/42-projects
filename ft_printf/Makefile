NAME		= libftprintf.a

SRC_DIR		= .

SRC			= ${SRC_DIR}/ft_printf.c \
				${SRC_DIR}/ft_create_output.c \
				${SRC_DIR}/ft_parsing_tags.c \
				${SRC_DIR}/ft_read_arg.c \
				${SRC_DIR}/ft_printf_parsing.c

OBJ			= $(SRC:.c=.o)

SRC_DIR_LIBFT	= libft

SRC_LIBFT	= ${SRC_DIR_LIBFT}/libft00.c \
				${SRC_DIR_LIBFT}/libft01.c \
				${SRC_DIR_LIBFT}/libft02.c \
				${SRC_DIR_LIBFT}/libft03.c \
				${SRC_DIR_LIBFT}/libft04.c \
				${SRC_DIR_LIBFT}/libft05.c \
				${SRC_DIR_LIBFT}/libft06.c \
				${SRC_DIR_LIBFT}/libft07.c \
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

RL			= ranlib

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${OBJ_LIBFT}
			${AR} $@ $^
			${RL} $@

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re