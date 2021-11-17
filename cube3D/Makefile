LIB_LINUX	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
LIB_MAC		= -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB			= $(LIB_LINUX)

CC			= clang
CFLAGS		= #-Wall -Wextra -Werror -g
RM			= rm -f
LIB_A		= libft/libft.a minilibx-linux/libmlx_Linux.a

#------------------------------COLOR------------------------------

nc=\033[0m
Green=\033[0;32m
BRed=\033[1;31m
BYellow=\033[1;33m
UGreen=\033[4;32m
On_Green=\033[42m

#----------------------------MANDATORY----------------------------

NAME		= cub3d

SRC_DIR		= .
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c color.c divers.c rendering.c \
				set_input.c drawing.c move_camera.c key_hook.c motion_hook.c \
				grid.c raycasting.c maths.c colision.c raycasting_dda.c \
				read_img.c get_next_line.c print_img.c)

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@
			@printf "$(On_Green) $(nc)"

$(NAME):	$(OBJS)
			@make -C libft
			@make -C minilibx-linux
			@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIB_A) $(LIB)
			@echo "\n$(Green)*** $(UGreen)Successfully compiling $(NAME)$(Green) ***$(nc)"

all:		$(NAME)

clean:
			@make clean -C libft
			@$(RM) $(OBJS)
			@echo "$(BRed)/!\\ $(BYellow)Remove $(NAME) obj$(BRed) /!\\ $(nc)"

fclean:		clean
			@make fclean -C libft
			@$(RM) $(NAME)
			@echo "$(BRed)/!\\ $(BYellow)Remove $(NAME)$(BRed) /!\\ $(nc)"

re:			fclean all

.PHONY:		all clean fclean re
