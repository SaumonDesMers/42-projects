#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int    main(void)
{
    printf("%d\t", isalpha('0'));
    printf("%d\t", isalpha('b'));
    printf("%d\t", isdigit('a'));
    printf("%d\t", isdigit('9'));
    printf("%d\t", isalnum('\n'));
    printf("%d\t", isalnum('8'));
    printf("%d\t", isascii(231));
    printf("%d\t", isascii(' '));
    printf("%d\t", isprint('\n'));
    printf("%d\n", isprint(' '));
    printf("%d\t", ft_isalpha('0'));
    printf("%d\t", ft_isalpha('b'));
    printf("%d\t", ft_isdigit('a'));
    printf("%d\t", ft_isdigit('9'));
    printf("%d\t", ft_isalnum('\n'));
    printf("%d\t", ft_isalnum('8'));
    printf("%d\t", ft_isascii(231));
    printf("%d\t", ft_isascii(' '));
    printf("%d\t", ft_isprint('\n'));
    printf("%d\n", ft_isprint(' '));
    return (0);
}