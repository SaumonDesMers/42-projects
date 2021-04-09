NAME		= libft.a

SRC_DIR		= .

SRCS		= ${SRC_DIR}/libft00.c \
				${SRC_DIR}/libft01.c \
				${SRC_DIR}/libft02.c \
				${SRC_DIR}/libft03.c \
				${SRC_DIR}/libft04.c \
				${SRC_DIR}/libft05.c \
				${SRC_DIR}/libft06.c \
				${SRC_DIR}/libft07.c

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

RL			= ranlib

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re