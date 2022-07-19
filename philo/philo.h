//
// Created by LudwigAndreas on 17.07.2022.
//

#ifndef PHILO_PHILO_H
# define PHILO_PHILO_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct arguments
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_meals;
} t_args;

int param_validator(t_args *params);

void params_constructor(int argc, char **argv, t_args *params);

int validator(int argc, char **argv, t_args *params);

int input_checker(int argc, char **argv, t_args *args);

#endif //PHILO_PHILO_H
