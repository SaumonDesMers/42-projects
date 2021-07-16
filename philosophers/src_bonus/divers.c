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

t_bool	error(char *msg)
{
	printf("%s\n", msg);
	return (ERROR);
}

void	ft_wait(t_philo *philo)
{
	t_time	wait;

	wait = philo->data->time_to_eat;
	if (wait == 0)
		wait = 1;
	if (philo->data->nb_of_philo % 2 == 0)
	{
		if (philo->philo_nb % 2 == 1 && philo->nb_of_meal == 0)
			ft_sleep(1, philo);
	}
	else
	{
		if (philo->nb_of_meal != 0)
			ft_sleep(2 * wait - philo->data->time_to_sleep, philo);
		else if (philo->philo_nb % 3 == 1)
			ft_sleep(wait, philo);
		else if (philo->philo_nb % 3 == 2)
			ft_sleep(2 * wait, philo);
	}
}
