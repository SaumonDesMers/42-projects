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

BONUS_SRCS	= ${SRC_DIR}/ft_lstnew.c \
				${SRC_DIR}/ft_lstadd_front.c \
				${SRC_DIR}/ft_lstsize.c \
				${SRC_DIR}/ft_lstlast.c \
				${SRC_DIR}/ft_lstadd_back.c

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RL			= ranlib

OBJS		= $(SRCS:.c=.o)

BONUS_OBJ	= $(BONUS_SRCS:.c=.o)

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

bonus:		$(OBJS) $(BONUS_OBJ)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJ)

so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS) $(BONUS_SRCS)
			gcc -shared -o libft.so $(OBJS) $(BONUS_OBJ)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re