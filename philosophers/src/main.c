#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	init_mutex(&data);
	data.starting_time = get_utime();
	i = 0;
	while (i < data.nb_of_philo)
	{
		init_philo(&data, &data.philo[i], i);
		pthread_create(&data.philo[i].philo_tid, NULL,
			&thread_philo, &data.philo[i]);
		i++;
	}
	i = 0;
	while (i < data.nb_of_philo)
		pthread_join(data.philo[i++].philo_tid, NULL);
	destroy_mutex(&data);
	free(data.philo);
	free(data.fork);
	return (0);
}
