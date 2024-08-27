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
	t_philo	*philos;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_times;
}	t_setting;

typedef struct s_philo
{
	t_setting		*settings;
	pthread_t		*thread;
	int				id;
	int				last_meal;
	int				start_time;
	int				dead;
	int				time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

/* init */
void *init(int argc, char **argv, t_setting *settings, t_philo *philos);
void alloc(t_philo *philos, t_setting *settings);
void init_data(int argc, char **argv, t_setting *settings);
void init_fork(t_setting *settings);
void init_philo(t_philo *philos, t_setting *settings);

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
void eat(t_setting *settings, t_philo *philo);
void take_fork(t_setting *settings, t_philo *philo);
void drop_fork(t_philo *philo);
void sleep_and_think(t_setting *settings, t_philo *philo);

#endif