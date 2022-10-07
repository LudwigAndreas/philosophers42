/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philo_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:39:37 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/28 17:39:39 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*check_satiety_thread(void *data)
{
	t_params	*params;
	int			i;

	params = (t_params *) data;
	i = 0;
	while (i++ <= params->num_of_philo)
		sem_wait(params->satisfied_sem);
	params->is_all_satiety = 1;
	return (NULL);
}

void	*check_death_thread(void *data)
{
	t_params	*params;
	int			i;

	i = 0;
	params = (t_params *) data;
	sem_wait(params->dead_sem);
	sem_wait(params->dead_sem);
	params->is_someone_dead = 1;
	sem_wait(params->stdout_sem);
	printf("%-6llu %-3lu %s%s%s\n",
		get_time() - params->startup, (unsigned long ) i + 1,
		ANSI_RED, "died\t", ANSI_RESET);
	return (NULL);
}

void	wait_philo_status(t_params *params)
{
	int			status1;
	int			status2;
	pthread_t	death_tid;
	pthread_t	satiety_tid;

	status1 = pthread_create(&death_tid, NULL, check_death_thread,
			(void *) params);
	status2 = pthread_create(&satiety_tid, NULL, check_satiety_thread,
			(void *) params);
	if (status1 != 0 || status2 != 0)
		return ;
	while (params->is_someone_dead == 0 && params->is_all_satiety == 0)
	{
		usleep(500);
	}
}

void	unlink_semaphores(void)
{
	sem_unlink("forks");
	sem_unlink("is_someone_dead");
	sem_unlink("satisfied_sem");
	sem_unlink("stdout_sem");
}
