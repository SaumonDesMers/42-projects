NAME		= pipex

SRC_DIR		= .
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c exec_cmd.c utils.c libft.c \
				ft_split.c ft_strjoin.c ft_gnl.c ft_putstr_fd.c ft_strncmp.c \
				ft_strdup.c fonction.c check_input.c)

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@ 
			@echo "Done"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@echo "Remove obj"

fclean:		clean
			@$(RM) $(NAME)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re