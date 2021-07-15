#include "philosophers.h"

long	get_utime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + time.tv_sec * 1000000);
}

void	ft_sleep(t_time time_ms, t_philo *philo)
{
	t_time	start;

	start = get_utime();
	while (get_utime() - start < time_ms * 1000)
	{
		if (get_utime() - philo->last_lunch_time
			> philo->data->time_to_die * 1000)
		{
			writing("died\n", philo);
			return ;
		}
		usleep(100);
	}
}

void	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
		kill(data->philo_pid[i++], 15);
}
