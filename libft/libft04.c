#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	if (!little[0])
		return ((char*)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

int ft_atoi(const char *nptr)
{
	int i;
	int nb;
	int signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+' || !nptr[i])
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + nptr[i++] - 48;
	return (nb * signe);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	if (!(ptr = malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((char*)ptr)[i++] = 0;
	return (ptr);
}

char *ft_strdup(const char *s)
{
	char	*dst;
	int 	i;

	i = 0;
	while (s[i])
		i++;
	if(!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}