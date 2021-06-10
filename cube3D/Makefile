NAME		= cube3d

LIB_LINUX	= -lft -lmlx -lXext -lX11 -lm -lbsd
LIB_MAC		= -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB		= $(LIB_LINUX)

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
				${SRC_DIR}/raycasting_dda.c \
				${SRC_DIR}/read_img.c \
				${SRC_DIR}/get_next_line.c \
				${SRC_DIR}/print_img.c \

OBJ_DIR		= obj
OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR_LIBFT	= libft

LIBFT_A		= ${SRC_DIR_LIBFT}/libft.a

CC			= cc

CFLAGS		= 

AR			= ar rcs

RL			= ranlib

RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o $@ $^ ${LIBFT_A} -L ./libft $(LIB)

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re