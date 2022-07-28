/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:39:07 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/28 17:39:10 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	start_line_printer(t_params *args)
{
	printf("NUM OF PHILO: %d\n"
		"TIME TO DIE: %d\n"
		"TIME TO EAT: %d\n"
		"TIME TO SLEEP: %d\n"
		"NUM OF MEALS: %d\n", args->num_of_philo, args->time_to_die,
		args->time_to_eat, args->time_to_sleep, args->num_of_meals);
	printf("| %s%-6s%sms | %s%-4s%s | %s%-16s%s\t|\n", ANSI_MAGNETA, "TIME",
		ANSI_RESET, ANSI_MAGNETA, "№  ",
		ANSI_RESET, ANSI_MAGNETA, "PHILO ACTION", ANSI_RESET);
}

int	main(int argc, char **argv)
{
	t_params	args;

	if (input_checker(argc, argv, &args) != 1)
		return (0);
	start_line_printer(&args);
	start_philo(&args);
	return (0);
}
