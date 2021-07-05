#include "philosophers.h"

void	philo_sleep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_utime() - philo->data->starting_time,
		philo->philo_nb);
	usleep(philo->data->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);

	philo->last_lunch_time = get_utime();
	philo->nb_of_meal++;
	printf("%ld %d is eating\n", get_utime() - philo->data->starting_time,
		philo->philo_nb);
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*thread_philo(void *void_philo)
{
	t_philo	*philo;

	philo = ((t_philo *)void_philo);
	philo->last_lunch_time = get_utime();
	while (philo->data->nb_of_meal_max == -1
		|| philo->nb_of_meal < philo->data->nb_of_meal_max)
	{
		philo_eat(philo);
		philo_sleep(philo);
		printf("%ld %d is thinking\n", get_utime() - philo->data->starting_time,
			philo->philo_nb);
		if (philo_dead(philo))
		{
			printf("%ld %d died\n", get_utime() - philo->data->starting_time,
				philo->philo_nb);
			return (NULL);
		}
	}
	return (NULL);
}
