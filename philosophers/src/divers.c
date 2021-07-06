#include "philosophers.h"

long	get_utime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + time.tv_sec * 1000000);
}

t_bool	philo_dead(t_philo *philo)
{
	return (get_utime() - philo->last_lunch_time > philo->data->time_to_die
		&& philo->last_lunch_time != -1);
}
