#include "../philo.h"

void args_printer(t_params *args)
{
	printf("NUM OF PHILO: %d\n"
		   "TIME TO DIE: %d\n"
		   "TIME TO EAT: %d\n"
		   "TIME TO SLEEP: %d\n"
		   "NUM OF MEALS: %d\n", args->num_of_philo, args->time_to_die,
		   args->time_to_eat, args->time_to_sleep, args->num_of_meals);
}

int main(int argc, char **argv)
{
	t_params args;
	if (input_checker(argc, argv, &args) != 1)
		return (0);
	args_printer(&args);
    start_philo(&args);
}