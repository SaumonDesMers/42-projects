NAME		= philo

SRC_DIR		= src
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c thread_philo.c ft_atoi.c \
				initialisation.c divers.c ft_putnbr_fd.c ft_strlen.c writing.c)

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= #-fsanitize=address #-Wall -Wextra -Werror
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