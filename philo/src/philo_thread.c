#include "../philo.h"

int	check_death(t_philo *philo)
{
	if (philo->params->is_someone_dead || philo->last_ate + philo->params->time_to_die <= get_time())
		return (0);
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