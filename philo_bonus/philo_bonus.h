#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

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

typedef unsigned long long	t_ull;

typedef pthread_mutex_t		t_mutex;

typedef struct s_params
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_meals;
	int		satisfied;
	sem_t	*satisfied_sem;
	t_ull	startup;
	sem_t	*stdout_sem;
	sem_t	*dead_sem;
	int		is_someone_dead;
	int		is_all_satiety;
}	t_params;

typedef struct s_philo
{
	pid_t		pid;
	size_t		id;
	t_ull		last_ate;
	int			num_ate;
	t_params	*params;
	sem_t		*forks;
}	t_philo;

int		input_checker(int argc, char **argv, t_params *args);

int		validator(int argc, char **argv, t_params *params);

void	params_constructor(int argc, char **argv, t_params *params);

int		param_validator(t_params *params);

int		ft_atoi(const char *str);

int		ft_isstrnumeric(char *str);

int		ft_isdigit(int c);

t_ull	get_time(void);

void	print_with_time(t_philo *philo, char *msg, t_ull ms, char *color);

void	wait_milliseconds(int milliseconds);

void	start_philo(t_params *params);

void	unlink_semaphores();

void	start_philo_processes(t_philo *philos);

void	pick_forks(t_philo *philo);

void	raise_forks(t_philo *philo);

void	philo_eating(t_philo *philo);

void	philo_sleeping(t_philo *philo);

void	philo_thinking(t_philo *philo);

void	philo_process(t_philo *philo);

void	kill_all_philos(t_philo *philos);

void	wait_philo_status(t_params *params);

void	close_semaphores(t_philo *philos);

int		check_death(t_philo *philo);
#endif
