NAME		= push_swap

SRC_DIR		= src
SRCS		=	$(patsubst %, $(SRC_DIR)/%, read_arg.c sort_stack.c push_swap_fonction.c utils.c checker.c)

MAIN_PUSH_SWAP	=	$(SRC_DIR)/main_push_swap.c
OBJ_PUSH_SWAP	=	$(MAIN_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MAIN_CHECKER	=	$(SRC_DIR)/main_checker.c
OBJ_CHECKER		=	$(MAIN_CHECKER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_DIR		= obj
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
				$(LIST_SRCS:$(LIST_DIR)/%.c=$(OBJ_DIR)/%.o) \

LIBS		= libft/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
AR			= ar rcs
RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS) $(OBJ_PUSH_SWAP)
			@make -C libft
			@$(CC) $(CFLAGS) $(OBJS) $(OBJ_PUSH_SWAP) $(LIBS) -o $@
			@echo "Done"

all:		$(NAME)

checker:	$(OBJS) $(OBJ_CHECKER)
			@make -C libft
			@$(CC) $(CFLAGS) $(OBJS) $(OBJ_CHECKER) $(LIBS) -o $@
			@echo "Done"

clean:
			@make clean -C libft
			@$(RM) $(OBJS) $(OBJ_PUSH_SWAP)
			@echo "Remove obj"

fclean:		clean
			@make fclean -C libft
			@$(RM) $(NAME) $(OBJ_PUSH_SWAP)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re