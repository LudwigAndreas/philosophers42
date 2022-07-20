#include "../philo.h"

void	philo_thinking(t_philo *philo)
{
	t_ull time;

	time = get_time() - philo->params->startup;
	print_with_time(philo, "is thinking", time, "\033[1;93m");
}

void	philo_sleeping(t_philo *philo)
{
	t_ull time;

	time = get_time() - philo->params->startup;
	print_with_time(philo, "is sleeping", time, "\033[1;97m");
	wait_milliseconds(philo->params->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
	t_ull time;

	time = get_time() - philo->params->startup;
	philo->num_ate += 1;
	print_with_time(philo, "is eating", time, "\033[1;92m");
	philo->last_ate = get_time();
	wait_milliseconds(philo->params->time_to_eat);
}

void	philo_wait(t_philo *philo)
{
	(void) philo;
}

int	check_death(t_philo *philo)
{
	if (philo->last_ate + philo->params->time_to_die <= get_time() || philo->params->is_someone_dead) {
		return (0);
	}
	return (1);
}

void	wait_at_start(t_philo *philo)
{
	if (philo->params->num_of_philo > 1)
	{
		if (philo->id % 2 == 0)
			wait_milliseconds(philo->params->time_to_eat);
//		else if (philo->id % 2 == 1)
//			wait_milliseconds(philo->params->time_to_eat);
	}
	(void) philo;
}

void	*philo_thread(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	wait_at_start(philo);
	while (check_death(philo))
	{
		philo_wait(philo);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}