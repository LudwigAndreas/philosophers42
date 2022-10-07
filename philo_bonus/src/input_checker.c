/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:00 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/21 15:50:01 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	param_type_validator(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_isstrnumeric(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	param_validator(t_params *params)
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

void	params_constructor(int argc, char **argv, t_params *params)
{
	params->num_of_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->num_of_meals = -1;
	if (argc == 6)
	{
		params->num_of_meals = ft_atoi(argv[5]);
		if (params->num_of_meals <= 0)
			params->num_of_meals = -2;
	}
}

int	validator(int argc, char **argv, t_params *params)
{
	int	param_err_code;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	if (!param_type_validator(argc, argv))
	{
		printf("Arguments must be numeric.\n");
		return (0);
	}
	params_constructor(argc, argv, params);
	param_err_code = param_validator(params);
	return (param_err_code);
}

int	input_checker(int argc, char **argv, t_params *args)
{
	int	err_num;

	err_num = validator(argc, argv, args);
	if (err_num != 1)
		printf("USAGE: %s./philo%s %snumber_of_philosophers%s"
			" %stime_to_die%s %stime_to_eat%s "
			"%stime_to_sleep%s "
			"[%snumber_of_times_each_philosopher_must_eat%s]\n",
			ANSI_BOLD, ANSI_RESET,
			ANSI_UNDERLINE, ANSI_RESET,
			ANSI_UNDERLINE, ANSI_RESET,
			ANSI_UNDERLINE, ANSI_RESET,
			ANSI_UNDERLINE, ANSI_RESET,
			ANSI_UNDERLINE, ANSI_RESET);
	return (err_num);
}
