#include "philosophers.h"

void	init_philo(t_data *data, t_philo *philo, int index)
{
	philo->data = data;
	philo->philo_nb = index;
	philo->left_fork = &data->fork[index];
	if (index == 0)
		philo->right_fork = &data->fork[data->nb_of_philo - 1];
	else
		philo->right_fork = &data->fork[index - 1];
	philo->last_lunch_time = -1;
	philo->nb_of_meal = 0;
}

int	init_data(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (ERROR);
	data->nb_of_philo = ft_atoi(av[1]);
	if (data->nb_of_philo < 1)
		return (ERROR);
	data->philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (data->philo == NULL || data->fork == NULL)
	{
		free(data->philo);
		free(data->fork);
		return (ERROR);
	}
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_of_meal_max = -1;
	if (ac == 6)
		data->nb_of_meal_max = ft_atoi(av[5]);
	data->a_philo_died = 0;
	return (SUCCESS);
}

void	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->pen, NULL);
	i = 0;
	while (i < data->nb_of_philo)
		pthread_mutex_init(&data->fork[i++], NULL);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->pen);
	i = 0;
	while (i < data->nb_of_philo)
		pthread_mutex_destroy(&data->fork[i++]);
}
