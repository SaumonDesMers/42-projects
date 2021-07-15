#include "philosophers.h"

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
		i = -1;
		while (++i < data->nb_of_philo)
			sem_post(data->wait_start);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	init_sem(&data);
	init_philo(&data, &data.philo);
	simulation(&data);
	waitpid(-1, NULL, 0);
	kill_all(&data);
	close_sem(&data);
	unlink_sem();
	free(data.philo_pid);
	return (0);
}
