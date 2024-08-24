#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	pthread_t		*thread;
	int				id;
	size_t			last_meal;
	size_t			start_time;
	int				dead;
	int				time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_setting
{
	// t_philo	*philos;
	pthread_mutex_t *fork;
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_times;
}	t_setting;

/* init */
void init(int argc, char **argv, t_setting *settings, t_philo *philos);
void init_data(int argc, char **argv, t_setting *settings);
void init_philo(t_setting *settings);
void init_fork(t_setting *settings);
void alloc(t_setting *settings);

/* util.c */
void    error_print(char *str);
void    check_args(int argc, char **argv);
void input_check(int argc, char **argv);

/* time.c */
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);

/* thread.c */
void action(void *p_philo, t_setting *settings);

#endif