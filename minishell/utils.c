#include "minishell.h"

void	error_catch(t_bool test, char *error_msg, t_root *root)
{
	if (test)
	{
		write(2, "Error : ", 8);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
		exit(0);
	}
}
