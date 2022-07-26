#include "../philo_bonus.h"

int aliveness(t_params *params, t_philo *philos)
{
	(void)params;
	(void )philos;
	return (1);
}

sem_t	*forks_constructor(t_params *params)
{
	sem_t	*forks;

	forks = malloc(sizeof(sem_t *));
	if (!forks)
		return (NULL);
	memset(forks, 0, sizeof(* forks));
	forks = sem_open("forks", O_CREAT, S_IRWXU, params->num_of_philo);
	return (forks);
}

t_philo	*philo_constructor(t_params *params)
{
	int		i;
	t_philo	*philos;
	sem_t	*forks;

	philos = (t_philo *) malloc(sizeof(t_philo) * params->num_of_philo);
	i = 1;
	forks = forks_constructor(params);
	while (i <= params->num_of_philo)
	{
		philos[i - 1].id = i;
		philos[i - 1].last_ate = get_time();
		philos[i - 1].num_ate = 0;
		philos[i - 1].params = params;
		philos[i - 1].forks = forks;
		i++;
	}
	return (philos);
}

void	start_philo(t_params *params)
{
	t_philo *philos;


	unlink_semaphores();
	params->is_someone_dead = 0;
	params->satisfied = 0;
	philos = philo_constructor(params);
	params->startup = get_time();
	params->stdout_sem = sem_open("stdout_sem", 1);
	start_philo_processes(philos);
	unlink_semaphores();
	exit(0);
}

void	start_philo_processes(t_philo *philos)
{
	int				i;
	pid_t			pid;

	i = 0;
	while (i < philos[0].params->num_of_philo)
	{
		pid = fork();
		if (pid == 0) {
			philo_process(&philos[i]);
			exit(0);
		}
//		} else if (pid < 0)
//			kill_all_philos(philos);
		else
			philos[i].pid = pid;
		i++;
	}
	check_suspending();
//	kill_all_philos(philos);
//	close_semaphores(philos);
}

//после начала в основном процессе запускается 2 потока, кадждый ждет своего
// первый ждет смерти любого из потоков, второй ждет, пока все наедятся с помощю
// while (params.num_of_philo)
//{
//		sem_wait(philo.satisfied);
//}
// exit(0);
