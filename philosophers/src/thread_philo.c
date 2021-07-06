#include "philosophers.h"

int	philo_sleep(t_philo *philo)
{
	writing("is sleeping\n", philo);
	usleep(philo->data->time_to_sleep);
	return (ALIVE);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	writing("has taken a fork\n", philo);
	pthread_mutex_lock(philo->right_fork);
	writing("has taken a fork\n", philo);

	philo->last_lunch_time = get_utime();
	philo->nb_of_meal++;
	writing("is eating\n", philo);
	usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (ALIVE);
}

void	*thread_philo(void *void_philo)
{
	t_philo	*philo;

	philo = ((t_philo *)void_philo);
	philo->last_lunch_time = get_utime();
	pthread_create(&philo->death_checker_tid, NULL, &check_time_to_live, philo);
	// if (philo->philo_nb % 2 == 1)
	// 	usleep(philo->data->time_to_eat);
	while ((philo->data->nb_of_meal_max == -1
		|| philo->nb_of_meal < philo->data->nb_of_meal_max)
		&& !philo->data->a_philo_died)
	{
		if (philo_eat(philo) == DEAD)
			return (NULL);
		if (philo_sleep(philo) == DEAD)
			return (NULL);
		writing("is thinking\n", philo);
	}
	return (NULL);
}

void	*check_time_to_live(void *void_philo)
{
	t_philo	*philo;

	philo = ((t_philo *)void_philo);
	while (!philo_dead(philo))
	{
		if (philo->data->a_philo_died)
			return (NULL);
	}
	writing("died\n", philo);
	return (NULL);
}
