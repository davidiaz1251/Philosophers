#include "philo.h"

void	free_all(t_philo *philos, t_config *cfg)
{
	int	i;

	if (cfg->forks)
	{
		i = 0;
		while (i < cfg->num_philos)
			pthread_mutex_destroy(&cfg->forks[i++]);
		free(cfg->forks);
	}
	pthread_mutex_destroy(&cfg->print_mutex);
	pthread_mutex_destroy(&cfg->death_mutex);
	if (philos)
		free(philos);
}