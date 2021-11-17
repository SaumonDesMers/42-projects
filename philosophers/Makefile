NAME		= philo
NAME_BONUS	= philo_bonus

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g#-lpthread
RM			= rm -f

#----------------------------MANDATORY----------------------------

SRC_DIR		= src
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c thread_philo.c ft_atoi.c \
				initialisation.c divers.c ft_putnbr_fd.c ft_strlen.c writing.c)
OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $@ 
			@echo "Done"

#------------------------------BONUS------------------------------

SRC_DIR_BONUS	= src_bonus
SRCS_BONUS		= $(patsubst %, $(SRC_DIR_BONUS)/%, main.c fork_philo.c ft_atoi.c \
				initialisation.c divers.c ft_putnbr_fd.c ft_strlen.c writing.c \
				simulation.c)
OBJ_DIR_BONUS	= obj_bonus
OBJS_BONUS		= $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR_BONUS)/%.o:$(SRC_DIR_BONUS)/%.c
			@mkdir -p $(OBJ_DIR_BONUS)
			@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME_BONUS):	$(OBJS_BONUS)
			@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@
			@echo "Done"

#-----------------------------------------------------------------

all:		$(NAME)

malloc_test: $(OBJS)
		$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} -L./otherlib/ -L. -lmallocator

bonus:		$(NAME_BONUS)

clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@echo "Remove obj & obj_bonus"

fclean:		clean
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "Remove $(NAME) & $(NAME_BONUS)"

re:			fclean all

.PHONY:		all clean fclean re bonus