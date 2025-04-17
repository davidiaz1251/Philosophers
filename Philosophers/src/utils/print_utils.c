#include "philo.h"

void	print_status(t_philo *philo, const char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->cfg->print_mutex);
	timestamp = get_timestamp_ms() - philo->cfg->start_time;
	if (!philo->cfg->stop_simulation)
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->cfg->print_mutex);
}