//
// Created by LudwigAndreas on 17.07.2022.
//

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef unsigned long long t_ull;

typedef pthread_mutex_t t_mutex;

typedef struct s_params
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_meals;
	int		satisfied;
	t_ull	startup;
	t_mutex	satisfied_mutex;
	t_mutex	stdout_mutex;
	int		is_someone_dead;
}	t_params;

typedef struct s_philo
{
	pthread_t	tid;
	size_t		id;
	t_ull		last_ate;
	int			num_ate;
	t_params	*params;
	t_mutex		*fork;
}	t_philo;

int		param_validator(t_params *params);

void	params_constructor(int argc, char **argv, t_params *params);

int		validator(int argc, char **argv, t_params *params);

int		input_checker(int argc, char **argv, t_params *args);

int		start_philo(t_params *args);

void	*philo_thread(void *vargp);
// additional functions
int		ft_atoi(const char *str);

unsigned long long get_time(void);

#endif
