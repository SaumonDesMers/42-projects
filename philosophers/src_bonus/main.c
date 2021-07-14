#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		pid;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	init_sem(&data);
	data.starting_time = get_utime();
	init_philo(&data, &data.philo, i);
	pid = 1;
	i = 0;
	while (i < data.nb_of_philo && pid != 0)
	{
		data.philo.philo_nb = i;
		data.philo_pid[i] = fork();
		pid = data.philo_pid[i];
		i++;
	}
	if (pid == 0 && data.philo_pid[data.philo.philo_nb] == 0)
	{
		fork_philo(&data.philo);
		sem_close(data.fork);
		sem_close(data.pen);
		exit (0);
	}
	while (wait(NULL) != -1)
		;
	destroy_sem(&data);
	free(data.philo_pid);
	return (0);
}
