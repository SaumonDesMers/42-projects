#include "libft.h"

int ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') ||
	 (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}