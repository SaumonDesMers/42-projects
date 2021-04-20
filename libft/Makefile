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

BONUS_OBJ	= ${SRC_DIR}/ft_lstnew.c \
				${SRC_DIR}/ft_lstadd_front

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RL			= ranlib

OBJS		= $(SRCS:.c=.o)

BONUS_OBJ	= $(BONUS:.c=.o)

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

bonus:		$(OBJ) $(BONUS_OBJ)
			$(AR) $(NAME) $^

so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re