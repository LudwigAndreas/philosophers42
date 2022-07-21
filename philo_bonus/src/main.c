#include "../philo_bonus.h"

//memset, printf, malloc, free, write, fork, kill,
//exit, pthread_create, pthread_detach, pthread_join,
//usleep, gettimeofday, waitpid, sem_open, sem_close,
//sem_post, sem_wait, sem_unlink


int main(int argc, char **argv)
{
	t_params	params;
//	t_philo		*philos;

	if (input_checker(argc, argv, &params) != 1)
		return (0);
}