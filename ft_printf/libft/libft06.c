#include "libft.h"

static int	nb_words(char *str, char c)
{
    int	count;
    int	i;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if (str[i] && str[i] != c)
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);
}

char		**ft_split(char *str, char c)
{
    char	**strs;
    int		len;
    int		i;
    int		j;

    len = nb_words(str, c);
    if (!(strs = malloc(sizeof(char *) * (len + 1))))
        return (NULL);
    i = 0;
    while (i < len)
    {
        while (*str && *str == c)
            str++;
        j = 0;
        while (str[j] && str[j] != c)
            j++;
        if (!(strs[i] = malloc(j + 1)))
            return (NULL);
        j = 0;
        while (*str && *str != c)
            strs[i][j++] = *str++;
        strs[i++][j] = 0;
    }
    strs[i] = 0;
    return (strs);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	while (s[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
        return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		write (fd, &s[i++], 1);
}