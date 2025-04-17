#include "philo.h"

int	get_timestamp_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(int ms)
{
	long	start;

	start = get_timestamp_ms();
	while (get_timestamp_ms() - start < ms)
		usleep(100);
}