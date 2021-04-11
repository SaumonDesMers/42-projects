#include "get_next_line.h"

static int ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '+')
		i++;
	return (i);
}

static int	no_newline(char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

static void	reset_buff(char buffer[BUFFER_SIZE + 1])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!no_newline(buffer))
	{
		while (buffer[i] != '+')
			i++;
		i++;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = 0;
	}
}
#include <stdio.h>
static char *ft_strjoin(char const *buffer, char *line)
{
    int     i;
    int     j;
    int     len;
	char	*newline;

    len = ft_strlen(buffer) + ft_strlen(line);
    if (!(newline = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    j = 0;
	if (line)
	{
		while (line[j])
        	newline[i++] = line[j++];
	}
    j = 0;
    while (buffer[j] && buffer[j] != '+')
        newline[i++] = buffer[j++];
    newline[i] = 0;
	free(line);
    return (newline);
}

int get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE + 1];
	int			ret;
	int i = 0;

	*line = NULL;
	while (no_newline(buffer) || !*line)
	{
		//printf("i:\t%d\n", i++);
		//printf("buffer:\t%s\nline:\t%s\n\n", buffer, *line);
		*line = ft_strjoin(buffer, *line);
		//printf("buffer:\t%s\nline:\t%s\n\n", buffer, *line);
		ret = read(fd, buffer, BUFFER_SIZE);
		//printf("buffer:\t%s\nline:\t%s\n\n", buffer, *line);
		if (ret)
			buffer[ret] = 0;
		if (!ret && no_newline(buffer))
			return (0);
		if (ret)
			*line = ft_strjoin(buffer, *line);
		//printf("buffer:\t%s\nline:\t%s\n\n", buffer, *line);
		//printf("--------------------------------------\n");
		if (no_newline(buffer))
			buffer[0] = 0;
	}	
	reset_buff(buffer);
	return (1);
}