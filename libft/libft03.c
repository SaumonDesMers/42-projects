#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i < 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int temp;

	i = 0;
	j = 0;
	temp = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i])
		i++;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = 0;
	if (size < temp)
		return (size + ft_strlen(src));
	else
		return (temp + ft_strlen(src));
}