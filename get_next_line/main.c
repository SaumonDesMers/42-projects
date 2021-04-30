#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void gnl(int fd)
{
	char * line = NULL;
	int gnlReturn = get_next_line(fd, &line);

	printf("%s(%d)\n", line, gnlReturn);
	free(line);
}

int main(int argc, char **argv)
{
	int	fd;
	int i = 0;
	
	(void)argc;
	(void)argv;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	while (i++ < 10)
		gnl(fd);
	close(fd);
	return (0);
}