LIB_LINUX	= -lft -lmlx -lXext -lX11 -lm -lbsd
LIB_MAC		= -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB			= $(LIB_LINUX)

NAME		= fractol

SRC_DIR		= .
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c color.c key_hook.c drawing.c maths.c complexe.c julia.c divers.c mouse_hook.c mandelbrot.c)

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS		= libft/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
AR			= ar rcs
RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS)
			@make -C libft
			@make -C minilibx-linux
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@ -L ./libft $(LIB)
			@echo "Done"

all:		$(NAME)

malloc_test: $(OBJS)
		$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} -L./otherlib/ -lyourlib -L. -lmallocator

clean:
			@make clean -C libft
			@make clean -C minilibx-linux
			@$(RM) $(OBJS)
			@echo "Remove obj"

fclean:		clean
			@make fclean -C libft
			@make clean -C minilibx-linux
			@$(RM) $(NAME)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re