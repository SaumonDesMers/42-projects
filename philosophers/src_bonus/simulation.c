#include "philosophers.h"

void	manage_death(t_data *data)
{
	int		pid_manage_death;

	pid_manage_death = fork();
	if (pid_manage_death == 0)
	{
		sem_wait(data->a_philo_died);
		kill_all(data);
		exit(0);
	}
}

void	simulation(t_data *data)
{
	int		i;
	int		pid;

	pid = 1;
	i = 0;
	while (i < data->nb_of_philo && pid != 0)
	{
		data->philo.philo_nb = i;
		pid = fork();
		data->philo_pid[i++] = pid;
	}
	if (pid == 0)
		fork_philo(&data->philo);
	else
	{
		manage_death(data);
		usleep(1000);
		i = -1;
		while (++i < data->nb_of_philo)
			sem_post(data->wait_start);
	}
	i = 0;
	while (i < data->nb_of_philo)
		waitpid(data->philo_pid[i++], NULL, 0);
}
