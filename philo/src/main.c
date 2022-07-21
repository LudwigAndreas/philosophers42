#include "../philo.h"

void start_line_printer(t_params *args)
{
	printf("NUM OF PHILO: %d\n"
		   "TIME TO DIE: %d\n"
		   "TIME TO EAT: %d\n"
		   "TIME TO SLEEP: %d\n"
		   "NUM OF MEALS: %d\n", args->num_of_philo, args->time_to_die,
		   args->time_to_eat, args->time_to_sleep, args->num_of_meals);
	printf("| %s%-6s%sms | %s%-4s%s | %s%-16s%s\t|\n", ANSI_MAGNETA, "TIME",ANSI_RESET, ANSI_MAGNETA, "№  ",
		   ANSI_RESET, ANSI_MAGNETA, "PHILO ACTION", ANSI_RESET);
}

void	destroy_mutex(t_params *params, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&params->stdout_mutex);
	i = 0;
	while (i < params->num_of_philo)
	{
		pthread_mutex_destroy(&(philos[0].fork[i]));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_params	args;
	t_philo		*philos;
	if (input_checker(argc, argv, &args) != 1)
		return (0);
	start_line_printer(&args);
    philos = start_philo(&args);
	while (aliveness(&args, philos))
	{
		usleep(500);
	}
	usleep(100000);
	destroy_mutex(&args, philos);
	return (0);
}