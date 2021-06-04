#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/src/libft.h"
# include <stdio.h>

int	check_arg(int ac, char **av);
int	*get_stack(int ac, char **av);

#endif