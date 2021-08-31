#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
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
