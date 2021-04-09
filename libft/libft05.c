#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t     i;
    size_t     j;
    char    *dst;

    j = 0;
    i = start;
    while (s[i] && j < len)
    {
        i++;
        j++;
    }
    if (!(dst = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    j = 0;
    i = start;
    while (s[i] && j < len)
        dst[j++] = s[i++];
    dst[j] = 0;
    return (dst);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int     i;
    int     j;
    int     len;
    char    *dst;

    len = ft_strlen(s1) + ft_strlen(s2);
    if (!(dst = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
        dst[i++] = s1[j++];
    j = 0;
    while (s2[j])
        dst[i++] = s2[j++];
    dst[i] = 0;
    return (dst);
}

static int is_set(char const *set, char c)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     len;
    char    *dst;

    i = 0;
    while (s1[i])
    {
        if (!is_set(set, s1[i]))
            len++;
        i++;
    }
    if (!(dst = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        if (!is_set(set, s1[i]))
            dst[i] = s1[i];
        i++;
    }
    dst[i] = 0;
    return (dst);
}

char *ft_itoa(int n)
{
    long    nb;
    char    *dst;
    int     i;

    nb = (long)n;
    i = 0;
    if (n <= 0)
        i++;
    while (n && i++ != -1)
        n /= 10;
    if (!(dst = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    dst[i--] = 0;
    if (nb < 0)
    {
        nb = -nb;
        dst[0] = '-';
    }
    if (nb == 0)
        dst[0] = '0';
    while (nb)
    {
        dst[i--] = nb % 10 + 48;
        nb /= 10;
    }
    return (dst);
}