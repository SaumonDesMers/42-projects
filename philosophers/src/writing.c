#include "philosophers.h"

int	writing(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->pen);
	if (philo->data->a_philo_died)
	{
		pthread_mutex_unlock(&philo->data->pen);
		return (DEAD);
	}

	ft_putnbr_fd(get_utime() - philo->data->starting_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->philo_nb, 1);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));

	if (msg[0] == 'd')
		philo->data->a_philo_died = 1;

	pthread_mutex_unlock(&philo->data->pen);

	return (ALIVE);
}
