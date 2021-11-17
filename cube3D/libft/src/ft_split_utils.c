#include "libft.h"

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	split_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	free_double_tab(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free((char *)tab[i++]);
	free(tab);
}
