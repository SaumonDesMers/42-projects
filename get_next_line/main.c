#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int	fd;
	int flag;
	
	(void)argc;
	(void)argv;

	fd = open("text.txt", O_RDONLY);
	while ((flag = get_next_line(fd, &line)))
	{
		if (flag == -1)
			return (0);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
