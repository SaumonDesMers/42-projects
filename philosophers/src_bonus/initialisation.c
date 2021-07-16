#include "philosophers.h"

void	init_philo(t_data *data, t_philo *philo)
{
	philo->data = data;
	philo->last_lunch_time = -1;
	philo->nb_of_meal = 0;
}

int	init_data(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (error("Wrong number of argument"));
	data->nb_of_philo = ft_atoi(av[1]);
	if (data->nb_of_philo < 1)
		return (error("Wrong number of philo"));
	if (init_sem(data) == ERROR)
		return (error("Semaphore open fail"));
	data->philo_pid = malloc(sizeof(int) * data->nb_of_philo);
	if (data->philo_pid == NULL)
		return (error("Malloc fail"));
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_of_meal_max = -1;
	if (ac == 6)
		data->nb_of_meal_max = ft_atoi(av[5]);
	init_philo(data, &data->philo);
	return (SUCCESS);
}

t_bool	init_sem(t_data *data)
{
	data->fork = sem_open("fork", O_CREAT, 0, data->nb_of_philo);
	data->pen = sem_open("pen", O_CREAT, 0, 1);
	data->wait_start = sem_open("wait_start", O_CREAT, 0, 0);
	data->a_philo_died = sem_open("a_philo_died", O_CREAT, 0, 0);
	if (data->fork == SEM_FAILED || data->pen == SEM_FAILED
		|| data->wait_start == SEM_FAILED || data->a_philo_died == SEM_FAILED)
	{
		close_sem(data);
		unlink_sem();
		return (ERROR);
	}
	return (SUCCESS);
}

void	close_sem(t_data *data)
{
	sem_close(data->fork);
	sem_close(data->pen);
	sem_close(data->wait_start);
	sem_close(data->a_philo_died);
}

void	unlink_sem(void)
{
	sem_unlink("fork");
	sem_unlink("pen");
	sem_unlink("wait_start");
	sem_unlink("a_philo_died");
}
