#include "philosophers.h"

void	philo_sleep(t_philo *philo)
{
	writing("is sleeping\n", philo);
	ft_sleep(philo->data->time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	writing("is thinking\n", philo);
	if (philo->data->time_to_die / 2 < philo->data->time_to_eat)
		ft_sleep(philo->data->time_to_eat, philo);
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
	ft_sleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

t_bool	end_loop(t_philo *philo)
{
	t_bool	retval;

	retval = 0;
	pthread_mutex_lock(&philo->data->pen);
	if (philo->data->a_philo_died)
		retval = 1;
	pthread_mutex_unlock(&philo->data->pen);
	return (retval);
}

void	*thread_philo(void *void_philo)
{
	t_philo	*philo;

	philo = ((t_philo *)void_philo);
	if (philo->data->nb_of_philo == 1)
	{
		printf("0 0 has taken a fork\n");
		usleep(philo->data->time_to_die * 1000);
		printf("%ld 0 died\n", philo->data->time_to_die);
		return (NULL);
	}
	philo->last_lunch_time = get_utime();
	if (philo->philo_nb % 2 == 1)
		ft_sleep(philo->data->time_to_eat, philo);
	while ((philo->data->nb_of_meal_max == -1
			|| philo->nb_of_meal < philo->data->nb_of_meal_max))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (end_loop(philo))
			break ;
	}
	return (NULL);
}
