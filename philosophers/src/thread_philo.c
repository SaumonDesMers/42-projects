#include "philosophers.h"

void	philo_sleep(t_philo *philo)
{
	writing("is sleeping\n", philo);
	usleep(philo->data->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	writing("has taken a fork\n", philo);
	pthread_mutex_lock(philo->right_fork);
	if (philo_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
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
		if (philo_dead(philo))
			return (NULL);
		philo_eat(philo);
		if (philo_dead(philo))
			return (NULL);
		philo_sleep(philo);
		if (philo_dead(philo))
			return (NULL);
		writing("is thinking\n", philo);
		pthread_mutex_lock(&philo->data->a_philo_died_mutex);
		if (philo->data->a_philo_died)
			return (NULL);
		pthread_mutex_unlock(&philo->data->a_philo_died_mutex);
	}
	return (NULL);
}

t_bool	philo_dead(t_philo *philo)
{
	if (get_utime() - philo->last_lunch_time > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->a_philo_died_mutex);
		if (philo->data->a_philo_died)
		{
			pthread_mutex_unlock(&philo->data->a_philo_died_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->a_philo_died_mutex);
		writing("died\n", philo);
		pthread_mutex_lock(&philo->data->a_philo_died_mutex);
		philo->data->a_philo_died = 1;
		pthread_mutex_unlock(&philo->data->a_philo_died_mutex);
		return (1);
	}
	return (0);
}
