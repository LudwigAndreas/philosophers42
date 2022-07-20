#include "../philo.h"

unsigned long long get_time(void)
{
	struct timeval curr_time;
	gettimeofday(&curr_time, NULL);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}

void	print_with_time(t_philo *philo, char *msg, t_ull ms, char *color)
{
	pthread_mutex_lock(&philo->params->stdout_mutex);
	if (!philo->params->is_someone_dead)
		printf("| %llums \t| %-2lu | %s%s%s\t|\n", ms, philo->id,
			   color, msg, "\033[0m");
	pthread_mutex_unlock(&philo->params->stdout_mutex);
}

void	wait_milliseconds(int milliseconds)
{
	t_ull	curr_time;

	curr_time = get_time();
	while (get_time() < curr_time + milliseconds)
		usleep(500);
}