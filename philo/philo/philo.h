/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:45:15 by mayu              #+#    #+#             */
/*   Updated: 2024/10/14 12:50:06 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_setting
{
	struct s_philo	*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	bool			dead_flag;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				eat_count;
}	t_setting;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_t		dead_thread;
	int				id;
	int				last_meal;
	int				eat_count;
	int				start_time;
	int				time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_setting		*settings;
}	t_philo;

/* init */
t_setting	*init_data(int argc, char **argv);
int			init_mutex(t_setting *settings);
t_philo		*init_philo(t_setting *settings);

/* util.c */
int			error_exit(char *str, t_setting *settings, t_philo *philos);
int			check_args(int argc, char **argv);
int			input_check(int argc, char **argv);
int			print_message(t_setting *settings, t_philo *philo, char *str);

/* time.c */
int			get_current_time(void);
void		ft_usleep(int milliseconds);

/* thread.c */
int			thread_init(t_philo *philos, t_setting *settings);
void		ft_exit(t_philo *philo, t_setting *settings);
void		*free_all(t_philo *philos, t_setting *settings);

/* action.c */
void		*is_dead(void *p_philo);
void		*action(void *p_philo);
int			eat(t_setting *settings, t_philo *philo);
int			take_fork(t_setting *settings, t_philo *philo);
void		drop_fork(t_philo *philo);
int			sleep_and_think(t_setting *settings, t_philo *philo);

/* libft_utils.c */
static int	skip_space(const char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

/* philo_utils.c */
int			check_args(int argc, char **argv);
int			input_check(int argc, char **argv);
int			print_message(t_setting *settings, t_philo *philo, char *str);

#endif
