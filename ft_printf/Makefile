NAME		= libftprintf.a

SRC_DIR		= .

SRCS		= ${SRC_DIR}/ft_printf.c \
				${SRC_DIR}/ft_create_output.c \
				${SRC_DIR}/ft_parsing_tags.c \
				${SRC_DIR}/ft_read_arg.c \
				${SRC_DIR}/ft_printf_parsing.c

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RL			= ranlib

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re