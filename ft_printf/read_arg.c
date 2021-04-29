#include "libft/libft.h"
#include "ft_printf.h"

int		nb_size(int nb)
{
	int len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
#include <stdio.h>
void	ft_itol(t_list **output, int n)
{
    long    nb;
	char	c[2];

    nb = (long)n;
	c[1] = 0;
    if (nb < 0)
        nb = -nb;
    if (nb == 0)
        ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
    while (nb)
    {
        c[0] = nb % 10 + 48;
		ft_lstadd_front(output, ft_lstnew(ft_strdup(c)));
        nb /= 10;
    }
	if (n < 0)
        ft_lstadd_front(output, ft_lstnew(ft_strdup("-")));
}