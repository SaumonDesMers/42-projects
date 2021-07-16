#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define NB_PHILO 5

typedef int				t_bool;
typedef long			t_time;
typedef struct s_data	t_data;

enum	e_key_words
{
	ERROR	= -1,
	SUCCESS	= 1,
	ALIVE,
	DEAD,
	ON,
	OFF
};

typedef struct s_sem
{
	int				val;
	pthread_mutex_t	val_mutex;
	t_bool			status;
	pthread_mutex_t	status_mutex;
}	t_sem;

typedef struct s_philo
{
	pthread_t		philo_tid;
	int				philo_nb;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_time			last_lunch_time;
	int				nb_of_meal;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	int				nb_of_meal_max;
	t_bool			a_philo_died;
	t_time			starting_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	pen;
	t_sem			even_turn;
	t_sem			odd_turn;
}	t_data;

void	*thread_philo(void *philo);

void	init_philo(t_data *data, t_philo *philo, int index);
int		init_data(int ac, char **av, t_data *data);
void	init_mutex(t_data *data);
void	destroy_mutex(t_data *data);

int		writing(char *msg, t_philo *philo);
void	ft_sleep(t_time time_ms, t_philo *philo);

int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(long n, int fd);
int		ft_strlen(const char *s);

long	get_utime(void);
void	ft_wait(t_philo *philo);

#endif