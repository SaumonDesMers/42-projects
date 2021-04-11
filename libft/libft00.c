#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t i;
	char *c_s;

	c_s = (char*)s;
	i = 0;
	while (i < n)
		c_s[i++] = c;
	return (s);
}

void ft_bzero(void *s, size_t n)
{
	size_t i;
	char *c_s;

	c_s = (char*)s;
	i = 0;
	while (i < n)
		c_s[i++] = 0;
}


void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *c_dest;
	char *c_src;

	c_dest = (char*)dest;
	c_src = (char*)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*c_dest;
	char	*c_src;

	c_dest = (char*)dest;
	c_src = (char*)src;
	i = 0;
	while (i < n && c_src[i] != c)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	if (c_src[i] == c)
	{
		c_dest[i] = (unsigned char)c_src[i];
		return (dest + i + 1);
	}
	return (NULL);
}


void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*c_dest;
	char	*c_src;

	c_dest = (char*)dest;
	c_src = (char*)src;
	if (c_src < c_dest)
	{
		i = n - 1;
		j = 0;
		while (j++ < n)
		{
			c_dest[i] = c_src[i];
			i--;
		}
	}
	else if (c_src > c_dest)
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}