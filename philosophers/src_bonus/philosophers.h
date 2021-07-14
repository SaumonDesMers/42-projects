#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define NB_PHILO 5

typedef int				t_bool;
typedef long			t_time;
typedef struct s_data	t_data;

enum	e_key_words
{
	ERROR	= -1,
	SUCCESS	= 1,
	ALIVE,
	DEAD
};

typedef struct s_philo
{
	int				philo_nb;
	t_time			last_lunch_time;
	int				nb_of_meal;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int		*philo_pid;
	int		nb_of_philo;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;
	int		nb_of_meal_max;
	t_bool	a_philo_died;
	t_time	starting_time;
	t_philo	philo;
	sem_t	*fork;
	sem_t	*pen;
}	t_data;

void	*fork_philo(void *philo);

void	init_philo(t_data *data, t_philo *philo, int index);
int		init_data(int ac, char **av, t_data *data);
void	init_sem(t_data *data);
void	destroy_sem(t_data *data);

int		writing(char *msg, t_philo *philo);
void	ft_sleep(t_time time_ms, t_philo *philo);

int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(long n, int fd);
int		ft_strlen(const char *s);

long	get_utime(void);

#endif