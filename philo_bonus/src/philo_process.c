#include "../philo_bonus.h"

void	*cycle_check_death_thread(void	*data)
{
	while (check_death((t_philo *) data))
	{
		usleep(500);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	if (philo->params->is_someone_dead == 1 || philo->last_ate + philo->params->time_to_die <= get_time())
	{
		sem_post(philo->params->dead_sem);
		return (0);
	}
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
	pthread_t	tid;

	pthread_create(&tid, NULL, cycle_check_death_thread, (void *) philo);
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
