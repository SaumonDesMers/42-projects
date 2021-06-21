#include "pipex.h"

int	count_cmd(int ac)
{
	if (ac < 3)
		return (-1);
	return(ac - 3);
}

void	error_catch(int test_value, int error_value, char *error_msg)
{
	if (test_value == error_value)
	{
		write(2, error_msg, ft_strlen(error_msg));
		exit(0);
	}
}
