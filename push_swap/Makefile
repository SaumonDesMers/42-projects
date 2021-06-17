NAME		= push_swap

OBJ_DIR		= obj
SRC_DIR		= src

SRCS		=	$(patsubst %, $(SRC_DIR)/%, main_push_swap.c read_arg.c sort_stack.c push_swap_fonction.c utils.c sorting_size_3.c)
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS	=	$(patsubst %, $(SRC_DIR)/%, main_checker.c read_arg.c push_swap_fonction.c utils.c checker.c)
OBJS_BUNUS	=	$(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


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

bonus:	$(OBJS_BUNUS)
			@make -C libft
			@$(CC) $(CFLAGS) $(OBJS_BUNUS) $(LIBS) -o checker
			@echo "Done"

clean:
			@make clean -C libft
			@$(RM) $(OBJS) $(OBJS_BUNUS)
			@echo "Remove obj"

fclean:		clean
			@make fclean -C libft
			@$(RM) $(NAME)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re