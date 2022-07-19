#include "../philo.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
//
//◦ number_of_philosophers: The number of philosophers and also the number of forks.
//
//◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
//  milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
//
//◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
//  During that time, they will need to hold two forks.
//
//◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
//
//◦ number_of_times_each_philosopher_must_eat (optional argument): If all
//  philosophers have eaten at least number_of_times_each_philosopher_must_eat
//  times, the simulation stops. If not specified, the simulation stops when a
//  philosopher dies.
//
//• Each philosopher has a number ranging from 1 to number_of_philosophers.
//
//• Philosopher number 1 sits next to philosopher number number_of_philosophers.
//  Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

int param_validator(t_params *params)
{
	if (params->num_of_philo <= 0)
		printf("Number of philosophers must be natural number\n");
	else if (params->time_to_die <= 0)
		printf("Time to die must be natural number\n");
	else if (params->time_to_eat <= 0)
		printf("Time to eat must be natural number\n");
	else if (params->time_to_sleep <= 0)
		printf("Time to sleep must be natural number\n");
	else if (params->num_of_meals <= 0 && params->num_of_meals != -1)
		printf("Number of times each philosopher must eat must"
			   " be natural number\n");
	else
		return (1);
	return (0);
}

void params_constructor(int argc, char **argv, t_params *params)
{
	params->num_of_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->num_of_meals = -1;
	if (argc == 6) {
		params->num_of_meals = ft_atoi(argv[5]);
		if (params->num_of_meals <= 0)
			params->num_of_meals = -2;
	}
}

int validator(int argc, char **argv, t_params *params)
{
	int param_err_code;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	params_constructor(argc, argv, params);
	param_err_code = param_validator(params);
	return param_err_code;
}

int input_checker(int argc, char **argv, t_params *args)
{
	int err_num;

	err_num = validator(argc, argv, args);
	if (err_num != 1)
		printf("USAGE: %s./philo%s %snumber_of_philosophers%s"
			   " %stime_to_die%s %stime_to_eat%s "
			   "%stime_to_sleep%s "
			   "[%snumber_of_times_each_philosopher_must_eat%s]\n",
			   "\033[1m", "\033[0m",
			   "\033[4m", "\033[0m",
			   "\033[4m", "\033[0m",
			   "\033[4m", "\033[0m",
			   "\033[4m", "\033[0m",
			   "\033[4m", "\033[0m");
	return err_num;
}