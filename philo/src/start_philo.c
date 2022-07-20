#include "../philo.h"

t_mutex	*forks_constructor(t_params *params)
{
	t_mutex *forks;
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
	t_philo *philos;
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

int start_philo(t_params *args)
{
	t_philo *philos;
	int		i;
	int		status;

	args->is_someone_dead = 0;
	args->satisfied = 0;
	pthread_mutex_init(&args->satisfied_mutex, NULL);
	pthread_mutex_init(&args->stdout_mutex, NULL);
	philos = philo_constructor(args);
	i = 1;
	args->startup = get_time();
	while (i <= args->num_of_philo)
	{
		status = pthread_create(&(philos[i - 1].tid), NULL, philo_thread, (void *) &philos[i - 1]);
		if (status != 0)
			return (0);
		i++;
	}
	while (1)
	{
		if (args->is_someone_dead != 0)
		{
			print_with_time(&philos[args->is_someone_dead], "died", get_time() - philos[args->is_someone_dead].params->startup, "\033[1;91m");
			return (0);
		}
	}
	return (0);
}