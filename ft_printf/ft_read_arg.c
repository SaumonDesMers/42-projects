#include "libft/libft.h"
#include "ft_printf.h"

void	ft_itol(t_list **output, long long n, char *base)
{
    long long	nb;
	char		c[2];

    nb = n;
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

void	ft_stol(t_list **output, char *str)
{
	char		c[2];

	c[1] = 0;
    if (!str)
        ft_stol(output, "(null)");
	else
	{
    	while (*str)
		{
			c[0] = *str;
			ft_lstadd_back(output, ft_lstnew(ft_strdup(c)));
			str++;
		}
    }
    
}

void	ft_ultol(t_list **output, unsigned long n, char *base)
{
    unsigned long	nb;
	char		    c[2];

    if (n == 0)
    {
        ft_stol(output, "(nil)");
        return ;
    }
    nb = n;
	c[1] = 0;
    if (nb == 0)
        ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
    while (nb)
    {
        c[0] = base[nb % ft_strlen(base)];
		ft_lstadd_front(output, ft_lstnew(ft_strdup(c)));
        nb /= ft_strlen(base);
    }
    ft_lstadd_front(output, ft_lstnew(ft_strdup("x")));
    ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
}