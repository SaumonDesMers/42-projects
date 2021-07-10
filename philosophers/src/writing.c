#include "philosophers.h"

t_bool	writing(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->pen);
	if (philo->data->a_philo_died)
	{
		pthread_mutex_unlock(&philo->data->pen);
		return (DEAD);
	}
	if (get_utime() - philo->last_lunch_time > philo->data->time_to_die)
	{
		msg = "died\n";
		philo->data->a_philo_died = 1;
	}

	// ft_putnbr_fd(get_utime() - philo->last_lunch_time, 1);
	// write(1, " ", 1);
	ft_putnbr_fd((get_utime() - philo->data->starting_time) / 1000, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->philo_nb, 1);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));

	pthread_mutex_unlock(&philo->data->pen);
	if (msg[0] == 'd')
		return (DEAD);
	return (ALIVE);
}
