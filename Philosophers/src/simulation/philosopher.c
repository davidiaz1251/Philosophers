#include "philo.h"

int	start_simulation(t_philo *philos, t_config *cfg)
{
	int			i;
	pthread_t	monitor;

	cfg->start_time = get_timestamp_ms();
	i = 0;
	while (i < cfg->num_philos)
	{
		philos[i].last_meal = cfg->start_time;
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
			return (1);
        pthread_detach(philos[i].thread);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
		return (1);

	pthread_join(monitor, NULL);

	return (0);
}