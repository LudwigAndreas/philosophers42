/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:50:02 by lsherry           #+#    #+#             */
/*   Updated: 2022/07/21 15:50:03 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_line_printer(void)
{
	printf("%s%-6s%s %s%-4s%s %s%-16s%s\n", ANSI_MAGNETA, "TIME",
		ANSI_RESET, ANSI_MAGNETA, "№  ",
		ANSI_RESET, ANSI_MAGNETA, "PHILO ACTION", ANSI_RESET);
}

void	destroy_mutex(t_params *params, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&params->stdout_mutex);
	pthread_mutex_destroy(&params->satisfied_mutex);
	i = 0;
	while (i < params->num_of_philo)
	{
		pthread_mutex_destroy(&(philos[0].fork[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_params	args;
	t_philo		*philos;

	if (input_checker(argc, argv, &args) != 1)
		return (0);
	start_line_printer();
	philos = start_philo(&args);
	while (aliveness(&args, philos))
	{
		usleep(500);
	}
	usleep(150000);
	destroy_mutex(&args, philos);
	return (0);
}
