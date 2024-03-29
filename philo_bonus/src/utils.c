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

#include "../philo_bonus.h"

unsigned long long	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}

void	print_with_time(t_philo *philo, char *msg, char *color)
{
	sem_wait(philo->params->stdout_sem);
	if (!philo->params->is_someone_dead)
		printf("%-6llu %-3lu %s%-16s%s\n", get_time() - philo->params->startup,
			philo->id, color, msg, ANSI_RESET);
	sem_post(philo->params->stdout_sem);
}

void	wait_milliseconds(int milliseconds)
{
	t_ull	curr_time;

	curr_time = get_time();
	while (1)
	{
		if (get_time() >= curr_time + milliseconds)
			break ;
		usleep(100);
	}
}

void	kill_all_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].params->num_of_philo)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
}

void	close_semaphores(t_philo *philos)
{
	sem_close(philos[0].forks);
	sem_close(philos[0].params->satisfied_sem);
	sem_close(philos[0].params->stdout_sem);
	sem_close(philos[0].params->dead_sem);
}
