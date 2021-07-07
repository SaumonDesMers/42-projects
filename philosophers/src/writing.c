#include "philosophers.h"

void	writing(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->pen);
	pthread_mutex_lock(&philo->data->a_philo_died_mutex);
	if (philo->data->a_philo_died)
	{
		pthread_mutex_unlock(&philo->data->pen);
		pthread_mutex_unlock(&philo->data->a_philo_died_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->a_philo_died_mutex);

	ft_putnbr_fd(get_utime() - philo->last_lunch_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(get_utime() - philo->data->starting_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->philo_nb, 1);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));

	pthread_mutex_unlock(&philo->data->pen);
}
