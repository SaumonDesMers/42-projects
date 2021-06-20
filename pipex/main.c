#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*arg[] = { av[1], av[2], NULL };
	char	*env[] = { NULL };
	int		pid = fork();

	if (pid == 0)
	{
		execve(av[1], arg, env);
	}
	wait(NULL);
	return (0);
}