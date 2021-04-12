#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*c_s;

	c_s = (unsigned char*)s;
	i = 0;
	while (i < n && c_s[i] != c)
		i++;
	if (c_s[i] == c)
		return (c_s + i);
	return (NULL);
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n && c_s1[i] == c_s2[i])
		i++;
	if (i == n)
		i--;
	return (c_s1[i] - c_s2[i]);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}