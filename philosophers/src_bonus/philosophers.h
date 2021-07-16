#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
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
	t_time	starting_time;
	t_philo	philo;
	sem_t	*fork;
	sem_t	*pen;
	sem_t	*wait_start;
	sem_t	*a_philo_died;
}	t_data;

void	fork_philo(t_philo *philo);

void	manage_death(t_data *data);
void	simulation(t_data *data);

void	init_philo(t_data *data, t_philo *philo);
int		init_data(int ac, char **av, t_data *data);
t_bool	init_sem(t_data *data);
void	close_sem(t_data *data);
void	unlink_sem(void);

void	writing(char *msg, t_philo *philo);

int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(long n, int fd);
int		ft_strlen(const char *s);

long	get_utime(void);
void	ft_sleep(t_time time_ms, t_philo *philo);
void	kill_all(t_data *data);
t_bool	error(char *msg);
void	ft_wait(t_philo *philo);

#endif