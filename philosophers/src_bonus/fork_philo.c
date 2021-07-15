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
	sem_wait(philo->data->fork);
	writing("has taken a fork\n", philo);
	sem_wait(philo->data->fork);
	writing("has taken a fork\n", philo);
	writing("is eating\n", philo);
	philo->nb_of_meal++;
	philo->last_lunch_time = get_utime();
	ft_sleep(philo->data->time_to_eat, philo);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	in_else(t_philo *philo)
{
	if (philo->philo_nb % 2 == 1)
		ft_sleep(philo->data->time_to_eat, philo);
	while (1)
	{
		philo_eat(philo);
		if (!(philo->data->nb_of_meal_max == -1
				|| philo->nb_of_meal < philo->data->nb_of_meal_max))
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	fork_philo(t_philo *philo)
{
	sem_wait(philo->data->wait_start);
	philo->data->starting_time = get_utime();
	philo->last_lunch_time = get_utime();
	if (philo->data->nb_of_philo == 1)
	{
		printf("0 0 has taken a fork\n");
		usleep(philo->data->time_to_die * 1000);
		printf("%ld 0 died\n", philo->data->time_to_die);
	}
	else
		in_else(philo);
	usleep((philo->data->time_to_eat * 2000
			+ philo->data->time_to_sleep * 2000));
	close_sem(philo->data);
	exit(0);
}
