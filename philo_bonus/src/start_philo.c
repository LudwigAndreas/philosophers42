/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:39:27 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/28 17:39:29 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

sem_t	*forks_constructor(t_params *params)
{
	sem_t	*forks;

	forks = sem_open("forks", O_CREAT, S_IRWXU, params->num_of_philo);
	return (forks);
}

t_philo	*philo_constructor(t_params *params)
{
	int		i;
	t_philo	*philos;
	sem_t	*forks;

	philos = (t_philo *) malloc(sizeof(t_philo) * params->num_of_philo);
	i = 1;
	forks = forks_constructor(params);
	while (i <= params->num_of_philo)
	{
		philos[i - 1].id = i;
		philos[i - 1].last_ate = get_time();
		philos[i - 1].num_ate = 0;
		philos[i - 1].params = params;
		philos[i - 1].forks = forks;
		i++;
	}
	return (philos);
}

void	start_philo(t_params *params)
{
	t_philo	*philos;

	unlink_semaphores();
	params->satisfied = 0;
	philos = philo_constructor(params);
	params->startup = get_time();
	params->is_all_satiety = 0;
	params->is_someone_dead = 0;
	params->dead_sem = sem_open("is_someone_dead", O_CREAT, S_IRWXU, 1);
	params->stdout_sem = sem_open("stdout_sem", O_CREAT, S_IRWXU, 1);
	params->satisfied_sem = sem_open("satisfied_sem", O_CREAT, S_IRWXU, 1);
	start_philo_processes(philos);
	unlink_semaphores();
	exit(0);
}

void	start_philo_processes(t_philo *philos)
{
	int				i;
	pid_t			pid;
	t_params		*params;

	params = philos[0].params;
	i = 0;
	while (i < philos[0].params->num_of_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			philo_process(&philos[i]);
			exit(0);
		}
		else if (pid < 0)
			kill_all_philos(philos);
		else
			philos[i].pid = pid;
		i++;
	}
	wait_philo_status(params);
	kill_all_philos(philos);
}
