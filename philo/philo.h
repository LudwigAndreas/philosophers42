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

# define ANSI_BOLD "\033[1m"
# define ANSI_UNDERLINE "\033[4m"
# define ANSI_RESET "\033[0m"
# define ANSI_RED "\033[1;91m"
# define ANSI_GREEN "\033[1;92m"
# define ANSI_YELLOW "\033[1;93m"
# define ANSI_BLUE "\033[1;94m"
# define ANSI_MAGNETA "\033[1;95m"
# define ANSI_CYAN "\033[1;96m"
# define ANSI_WHITE "\033[1;97m"


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

t_philo	*start_philo(t_params *args);

void	*philo_thread(void *vargp);

int aliveness(t_params *params, t_philo *philos);

void	philo_thinking(t_philo *philo);

void	philo_sleeping(t_philo *philo);

void	philo_eating(t_philo *philo);

void	philo_wait(t_philo *philo);

int		check_death(t_philo *philo);

void	pick_forks(t_philo *philo);

void	raise_forks(t_philo *philo);

unsigned long long get_time(void);

void	print_with_time(t_philo *philo, char *msg, t_ull ms, char *color);

void	wait_milliseconds(int milliseconds);

// additional functions
int		ft_atoi(const char *str);

int		ft_isdigit(int c);

#endif
