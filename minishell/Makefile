CC			= gcc
CFLAGS		= -fsanitize=address -g #-Wall -Wextra -Werror
RM			= rm -f
LIB			= libft/libft.a

#----------------------------MANDATORY----------------------------

NAME		= minishell

SRC_DIR		= .
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c exec_cmd.c fonction.c \
				utils.c)
OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS)
			@make -C libft
			@$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $@ -lreadline
			@echo "Done"

#------------------------------BONUS------------------------------

NAME_BONUS	= name_bonus

SRC_DIR_BONUS	= .
SRCS_BONUS		= $(patsubst %, $(SRC_DIR_BONUS)/%,)
OBJ_DIR_BONUS	= obj_bonus
OBJS_BONUS		= $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR_BONUS)/%.o:$(SRC_DIR_BONUS)/%.c
			@mkdir -p $(OBJ_DIR_BONUS)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME_BONUS):	$(OBJS_BONUS)
			@make -C libft
			@$(CC) $(CFLAGS) $(LIB) $(OBJS_BONUS) -o $@ -lreadline
			@echo "Done"

#-----------------------------------------------------------------

all:		$(NAME)

bonus:		$(NAME_BONUS)

clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@echo "Remove obj & obj_bonus"

fclean:		clean
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "Remove $(NAME) & $(NAME_BONUS)"

re:			fclean all

.PHONY:		all clean fclean re bonus