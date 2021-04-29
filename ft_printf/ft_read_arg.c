#include "libft/libft.h"
#include "ft_printf.h"

void	ft_itol(t_list **output, long long n, char *base)
{
    long long	nb;
	char		c[2];

    nb = (long long)n;
	c[1] = 0;
    if (nb < 0)
        nb = -nb;
    if (nb == 0)
        ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
    while (nb)
    {
        c[0] = base[nb % ft_strlen(base)];
		ft_lstadd_front(output, ft_lstnew(ft_strdup(c)));
        nb /= ft_strlen(base);
    }
	if (n < 0)
        ft_lstadd_front(output, ft_lstnew(ft_strdup("-")));
}