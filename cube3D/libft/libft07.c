#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		write (fd, &s[i++], 1);
	write (fd, "\n", 1);
}

void ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		write (fd, "-", 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = nb % 10 + 48;
	write (fd, &c, 1);
}