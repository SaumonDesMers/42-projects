#include "philosophers.h"

void	ft_putnbr_fd(long n, int fd)
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
