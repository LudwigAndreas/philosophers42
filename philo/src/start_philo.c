/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:18 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/21 15:50:19 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	aliveness(t_params *params, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < params->num_of_philo)
	{
		if (philos[i].last_ate + params->time_to_die <= get_time()
			|| params->is_someone_dead)
		{
			pthread_mutex_lock(&params->stdout_mutex);
			params->is_someone_dead = 1;
			printf("%-6llu %-3lu %s%s%s\n",
				get_time() - params->startup, (unsigned long ) i + 1,
				ANSI_RED, "died\t", ANSI_RESET);
			return (0);
		}
		if (params->satisfied == params->num_of_philo)
			return (0);
		i++;
	}
	return (1);
}

t_mutex	*forks_constructor(t_params *params)
{
	t_mutex	*forks;
	int		i;

	forks = (t_mutex *) malloc(sizeof(t_mutex) * params->num_of_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < params->num_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*philo_constructor(t_params *params)
{
	int		i;
	t_philo	*philos;
	t_mutex	*forks;

	philos = (t_philo *) malloc(sizeof(t_philo) * params->num_of_philo);
	i = 1;
	forks = forks_constructor(params);
	while (i <= params->num_of_philo)
	{
		philos[i - 1].id = i;
		philos[i - 1].last_ate = get_time();
		philos[i - 1].num_ate = 0;
		philos[i - 1].params = params;
		philos[i - 1].fork = forks;
		i++;
	}
	return (philos);
}

t_philo	*start_philo(t_params *args)
{
	int		i;
	int		status;
	t_philo	*philos;

	args->is_someone_dead = 0;
	args->satisfied = 0;
	pthread_mutex_init(&args->satisfied_mutex, NULL);
	pthread_mutex_init(&args->stdout_mutex, NULL);
	philos = philo_constructor(args);
	i = 1;
	args->startup = get_time();
	while (i <= args->num_of_philo)
	{
		status = pthread_create(&(philos[i - 1].tid), NULL, philo_thread,
				(void *) &philos[i - 1]);
		if (status != 0)
			return (0);
		i++;
	}
	return (philos);
}
