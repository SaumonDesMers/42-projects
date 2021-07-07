#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	pthread_mutex_init(&data.pen, NULL);
	pthread_mutex_init(&data.a_philo_died_mutex, NULL);
	i = 0;
	while (i < data.nb_of_philo)
		pthread_mutex_init(&data.fork[i++], NULL);
	data.starting_time = get_utime();
	i = 0;
	while (i < data.nb_of_philo)
	{
		init_philo(&data, &data.philo[i], i);
		pthread_create(&data.philo[i].philo_tid, NULL,
			&thread_philo, &data.philo[i]);
		i++;
	}
	while (!data.a_philo_died)
		;
	pthread_mutex_unlock(&data.a_philo_died_mutex);
	pthread_mutex_destroy(&data.a_philo_died_mutex);
	pthread_mutex_unlock(&data.pen);
	pthread_mutex_destroy(&data.pen);
	i = 0;
	while (i < data.nb_of_philo)
	{
		pthread_mutex_unlock(&data.fork[i++]);
		pthread_mutex_destroy(&data.fork[i++]);
	}
	i = 0;
	while (i < data.nb_of_philo)
		pthread_join(data.philo[i++].philo_tid, NULL);
	free(data.philo);
	free(data.fork);
	return (0);
}
