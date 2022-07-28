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

#include "../philo_bonus.h"

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
		sem_post(philo->params->satisfied_sem);
}

void	pick_forks(t_philo *philo)
{
	if (check_death(philo))
	{
		sem_wait(philo->forks);
		print_with_time(philo, "has taken a fork",
						get_time() - philo->params->startup, ANSI_CYAN);
		sem_wait(philo->forks);
		print_with_time(philo, "has taken a fork",
						get_time() - philo->params->startup, ANSI_CYAN);
	}
}

void	raise_forks(t_philo *philo)
{
	if (check_death(philo))
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
	}
}
