#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/src/libft.h"
# include <stdio.h>

typedef struct	s_value
{
	int	value;
	int	index;
}	t_value;

typedef struct	s_root
{
	t_value	*stack_a;
	int		size _a;
	t_value	*stack_b;
	int		size _b;
}	t_root;

int		check_arg(int ac, char **av);
int		get_stack(int ac, char **av, t_root *root);

void	free_all(t_root *root);

#endif