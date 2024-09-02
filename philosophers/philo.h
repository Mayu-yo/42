#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../libft/libft.h"


typedef struct s_setting
{
	pthread_t		*thread;
	struct s_philo	*philos;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
	pthread_mutex_t *dead;
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_times;
}	t_setting;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				last_meal;
	int				start_time;
	// int				dead;
	int				time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_setting		*settings;
}	t_philo;

/* init */
t_setting *init_data(int argc, char **argv);
void init_mutex(t_setting *settings);
t_philo *init_philo(t_setting *settings);

/* util.c */
void    error_print(char *str);
void    check_args(int argc, char **argv);
void input_check(int argc, char **argv);
void print_message(t_setting *settings, t_philo *philo, char *str);


/* time.c */
int	get_current_time(void);
int	ft_usleep(int milliseconds);

/* thread.c */
void thread_init(t_philo *philos, t_setting *settings);
void thread_destroy(t_philo *philos, t_setting *settings);

/* action.c */
void *action(void *p_philo);
// void *action(t_philo *philo);
void eat(t_setting *settings, t_philo *philo);
void take_fork(t_setting *settings, t_philo *philo);
// int take_fork(t_setting *settings, t_philo *philo);
void drop_fork(t_philo *philo);
void sleep_and_think(t_setting *settings, t_philo *philo);

#endif