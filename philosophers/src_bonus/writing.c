#include "philosophers.h"

void	writing(char *msg, t_philo *philo)
{
	sem_wait(philo->data->pen);
	if (get_utime() - philo->last_lunch_time > philo->data->time_to_die * 1000)
		msg = "died\n";
	ft_putnbr_fd((get_utime() - philo->last_lunch_time) / 1000, 1);
	write(1, " ", 1);
	ft_putnbr_fd((get_utime() - philo->data->starting_time) / 1000, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->philo_nb, 1);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
	if (msg[0] == 'd')
	{
		sem_post(philo->data->a_philo_died);
		close_sem(philo->data);
		exit(0);
	}
	sem_post(philo->data->pen);
}
