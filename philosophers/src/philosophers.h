#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define NB_PHILO 5

typedef int				t_bool;
typedef struct s_data	t_data;

enum	e_key_words
{
	ERROR = -1,
	SUCCESS = 1
};

typedef struct s_philo
{
	pthread_t		tid;
	int				philo_nb;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_lunch_time;
	int				nb_of_meal;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meal_max;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	long			starting_time;
}	t_data;

void	*thread_philo(void *philo);

void	init_philo(t_data *data, t_philo *philo, int index);
int		init_data(int ac, char **av, t_data *data);

int		ft_atoi(const char *nptr);

t_bool	philo_dead(t_philo *philo);
long	get_utime();

#endif