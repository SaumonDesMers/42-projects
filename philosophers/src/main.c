#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	pthread_mutex_init(&data.pen, NULL);
	i = 0;
	while (i < data.nb_of_philo)
		pthread_mutex_init(&data.fork[i++], NULL);
	i = 0;
	while (i < data.nb_of_philo)
	{
		init_philo(&data, &data.philo[i], i);
		pthread_create(&data.philo[i].philo_tid, NULL, &thread_philo, &data.philo[i]);
		i++;
	}
	while (data.nb_of_philo_ready < data.nb_of_philo)
		;
	data.starting_time = get_utime();
	data.start_simulation = 1;
	// i = 0;
	// while (i < data.nb_of_philo)
	// 	pthread_join(data.philo[i++].philo_tid, NULL);
	while (!data.a_philo_died)
		;
	i = 0;
	while (i < data.nb_of_philo)
		pthread_mutex_destroy(&data.fork[i++]);
	free(data.philo);
	free(data.fork);
	return (0);
}
