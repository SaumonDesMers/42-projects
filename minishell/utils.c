#include "minishell.h"

t_bool	error_catch(t_bool test, char *str, char *error_msg)
{
	if (test)
	{
		write(2, "minishell: ", 8);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	return (test);
}
