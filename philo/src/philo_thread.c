#include "../philo.h"
void	printing(t_philo *philo, char *philo_status, char *color)
{
	pthread_mutex_lock(&philo->params->stdout_mutex);
	printf("|%lld ms| %d | %sis %s%s\n", get_time() - philo->params->startup,
		   (int ) philo->id, color, philo_status, "\033[0m");
	pthread_mutex_unlock(&philo->params->stdout_mutex);
}

void	philo_thinking(t_philo *philo)
{
	printing(philo, "thinking", "\033[1;103m");
}

void	philo_sleeping(t_philo *philo)
{
	printing(philo, "sleeping", "\033[1;107m");
	usleep(philo->params->time_to_sleep * 1000);
}

void	philo_eating(t_philo *philo)
{
	printing(philo, "eating", "\033[1;102m");
	usleep(philo->params->time_to_eat * 1000);
}

void	philo_wait(t_philo *philo)
{
	(void) philo;
}

int	check_death(t_philo *philo)
{
	(void) philo;
	return (1);
}

void	wait_at_start(t_philo *philo)
{
//	if (philo->id %)
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