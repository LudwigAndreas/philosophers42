#include "../philo_bonus.h"

int	check_death(t_philo *philo)
{
//	if (philo->params->is_someone_dead
//		|| philo->last_ate + philo->params->time_to_die <= get_time())
//		return (0);
	(void) philo;
	return (1);
}

void	wait_at_start(t_philo *philo)
{
	if (philo->params->num_of_philo > 1)
	{
		if (philo->id % 2 == 1
			&& (int ) philo->id != philo->params->num_of_philo)
			wait_milliseconds(philo->params->time_to_eat * .95);
		else if (philo->params->num_of_philo % 2 == 1
				 && (int ) philo->id == philo->params->num_of_philo)
			wait_milliseconds(philo->params->time_to_eat);
	}
}

void	philo_process(t_philo *philo)
{
	wait_at_start(philo);
	while (check_death(philo))
	{
		philo_eating(philo);
		if (philo->num_ate == philo->params->num_of_meals)
			break ;
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return;
}
