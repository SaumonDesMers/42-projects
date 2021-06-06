NAME		= a.out

SRC_DIR		= .
SRCS		=	$(patsubst %, $(SRC_DIR)/%, main.c read_arg.c sort_stack.c push_swap_fonction.c)

OBJ_DIR		= .
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
				$(LIST_SRCS:$(LIST_DIR)/%.c=$(OBJ_DIR)/%.o) \

LIBS		= libft/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS)
			@make -C libft
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
			@echo "Done"

all:		$(NAME)

clean:
#			@make clean -C libft
			@$(RM) $(OBJS)
			@echo "Remove obj"

fclean:		clean
#			@make fclean -C libft
			@$(RM) $(NAME)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re