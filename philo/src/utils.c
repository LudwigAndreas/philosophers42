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

	gettimeofday(&curr_time, NULL);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}

void	print_with_time(t_philo *philo, char *msg, t_ull ms, char *color)
{
	pthread_mutex_lock(&philo->params->stdout_mutex);
	if (!philo->params->is_someone_dead)
		printf("| %-6llums | %-3lu | %s%-16s%s\t|\n", ms, philo->id,
			color, msg, ANSI_RESET);
	pthread_mutex_unlock(&philo->params->stdout_mutex);
}

void	wait_milliseconds(int milliseconds)
{
	t_ull	curr_time;

	curr_time = get_time();
	while (get_time() < curr_time + milliseconds)
		usleep(500);
}

void	pick_forks(t_philo *philo)
{
	if (check_death(philo))
	{
		pthread_mutex_lock(&philo->fork[philo->id
			% philo->params->num_of_philo]);
		print_with_time(philo, "has taken a fork",
			get_time() - philo->params->startup, ANSI_CYAN);
		pthread_mutex_lock(&philo->fork[(philo->id + 1)
			% philo->params->num_of_philo]);
		print_with_time(philo, "has taken a fork",
			get_time() - philo->params->startup, ANSI_CYAN);
	}
}

void	raise_forks(t_philo *philo)
{
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->fork[philo->id - 1
			% philo->params->num_of_philo]);
		pthread_mutex_unlock(&philo->fork[(philo->id)
			% philo->params->num_of_philo]);
	}
}
