/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:44 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/21 15:50:45 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long long	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, 0);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}

/*void	print_with_time(t_philo *philo, char *msg, char *color)
{
	(void ) color;
	pthread_mutex_lock(&philo->params->stdout_mutex);
	printf("%llu %lu %s\n", get_time() - philo->params->startup,
		   philo->id, msg);
	pthread_mutex_unlock(&philo->params->stdout_mutex);
}*/

void	print_with_time(t_philo *philo, char *msg, char *color)
{
	pthread_mutex_lock(&philo->params->stdout_mutex);
	printf("%-6llu %-3lu %s%-16s%s\n", get_time() - philo->params->startup,
		philo->id, color, msg, ANSI_RESET);
	pthread_mutex_unlock(&philo->params->stdout_mutex);
}

void	wait_milliseconds(int milliseconds)
{
	const t_ull	curr_time = get_time();

	while (1)
	{
		if (get_time() >= curr_time + milliseconds)
			break ;
		usleep(100);
	}
}
