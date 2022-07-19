#include "../philo.h"



void	*philo_thread(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
//	pthread_mutex_lock(&philo->params->stdout_mutex);
//	printf("ms: %lld\n", get_time() - philo->params->startup);
//	sleep(1);
//	pthread_mutex_unlock(&philo->params->stdout_mutex);
	wait_at_start(philo);
	while (check_death(philo))
	{
		philo_wait();
		philo_eating();
		philo_sleeping();
		philo_thinking();
	}
//	(void) vargp;
	return (NULL);
}