NAME		= a.out

SRC_DIR		= .

SRCS		= ${SRC_DIR}/ft.printf.c

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

bonus:		$(OBJS) $(BONUS_OBJ)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJ)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re