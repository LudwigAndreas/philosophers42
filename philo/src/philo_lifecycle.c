/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:10 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/21 15:50:11 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_thinking(t_philo *philo)
{
	print_with_time(philo, "is thinking",
		get_time() - philo->params->startup, ANSI_YELLOW);
}

void	philo_sleeping(t_philo *philo)
{
	print_with_time(philo, "is sleeping",
		get_time() - philo->params->startup, ANSI_WHITE);
	wait_milliseconds(philo->params->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
	pick_forks(philo);
	philo->num_ate += 1;
	print_with_time(philo, "is eating",
		get_time() - philo->params->startup, ANSI_GREEN);
	wait_milliseconds(philo->params->time_to_eat);
	philo->last_ate = get_time();
	raise_forks(philo);
	if (philo->num_ate == philo->params->num_of_meals)
	{
		pthread_mutex_lock(&philo->params->satisfied_mutex);
		philo->params->satisfied += 1;
		pthread_mutex_unlock(&philo->params->satisfied_mutex);
	}
}

void	philo_wait(t_philo *philo)
{
	(void) philo;
}
