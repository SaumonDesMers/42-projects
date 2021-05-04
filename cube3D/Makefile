NAME		= cube3d

SRC_DIR		= .

SRC			= ${SRC_DIR}/main.c \
				${SRC_DIR}/color.c \
				${SRC_DIR}/divers.c \
				${SRC_DIR}/rendering.c \
				${SRC_DIR}/set_input.c \
				${SRC_DIR}/drawing.c \
				${SRC_DIR}/move_camera.c \
				${SRC_DIR}/key_hook.c \
				${SRC_DIR}/motion_hook.c \
				${SRC_DIR}/grid.c \
				${SRC_DIR}/raycasting.c \
				${SRC_DIR}/maths.c \
				${SRC_DIR}/colision.c \
				${SRC_DIR}/DDA.c \

OBJ			= $(SRC:.c=.o)

SRC_DIR_LIBFT	= libft

LIBFT_A		= ${SRC_DIR_LIBFT}/libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RL			= ranlib

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o $@ $^ ${LIBFT_A} -L ./libft -lft -lmlx -lXext -lX11 -lm -lbsd

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re