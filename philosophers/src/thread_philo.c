#include "philosophers.h"

void	philo_sleep(t_philo *philo)
{
	writing("is sleeping\n", philo);
	usleep(philo->data->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	writing("has taken a fork\n", philo);

	pthread_mutex_lock(philo->right_fork);
	writing("has taken a fork\n", philo);

	writing("is eating\n", philo);
	philo->nb_of_meal++;
	philo->last_lunch_time = get_utime();
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*thread_philo(void *void_philo)
{
	t_philo	*philo;

	philo = ((t_philo *)void_philo);
	philo->last_lunch_time = get_utime();
	if (philo->philo_nb % 2 == 1)
		usleep(philo->data->time_to_eat);
	while ((philo->data->nb_of_meal_max == -1
			|| philo->nb_of_meal < philo->data->nb_of_meal_max))
	{
		philo_eat(philo);
		philo_sleep(philo);
		if (writing("is thinking\n", philo) == DEAD)
			break ;
	}
	// printf("%d\n", philo->philo_nb);
	return (NULL);
}
