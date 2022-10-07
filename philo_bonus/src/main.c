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

void	start_line_printer(void)
{
	printf("%s%-6s%s %s%-4s%s %s%-16s%s\n", ANSI_MAGNETA, "TIME",
		ANSI_RESET, ANSI_MAGNETA, "№  ",
		ANSI_RESET, ANSI_MAGNETA, "PHILO ACTION", ANSI_RESET);
}

int	main(int argc, char **argv)
{
	t_params	args;

	if (input_checker(argc, argv, &args) != 1)
		return (0);
	start_line_printer();
	start_philo(&args);
	return (0);
}
