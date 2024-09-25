/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:23:08 by mayu              #+#    #+#             */
/*   Updated: 2024/09/25 22:26:37 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_current_time(void)
{
	int				ret_time;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error_exit("gettimeofday error", NULL, NULL));
	ret_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret_time);
}

void	ft_usleep(int time)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(500);
}
