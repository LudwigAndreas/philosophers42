#include "../philo.h"

void	philo_thinking(t_philo *philo)
{
	print_with_time(philo, "is thinking", get_time() - philo->params->startup, ANSI_YELLOW);
}

void	philo_sleeping(t_philo *philo)
{
	print_with_time(philo, "is sleeping", get_time() - philo->params->startup, ANSI_WHITE);
	wait_milliseconds(philo->params->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
//	print_with_time(philo, "try to eat", get_time() - philo->params->startup, ANSI_GREEN);
	pick_forks(philo);
	philo->num_ate += 1;
	print_with_time(philo, "is eating", get_time() - philo->params->startup, ANSI_GREEN);
	wait_milliseconds(philo->params->time_to_eat);
	philo->last_ate = get_time();
	raise_forks(philo);
}

void	philo_wait(t_philo *philo)
{
	if (philo->params->num_of_philo != 1)
	{

	}
	(void) philo;
}
