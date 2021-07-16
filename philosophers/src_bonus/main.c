#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (init_data(ac, av, &data) == ERROR)
		return (0);
	simulation(&data);
	close_sem(&data);
	unlink_sem();
	free(data.philo_pid);
	return (0);
}
