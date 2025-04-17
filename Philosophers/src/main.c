#include "philo.h"

static void	print_config(t_config *cfg)
{
	printf("Número de filósofos: %d\n", cfg->num_philos);
	printf("Tiempo para morir: %d\n", cfg->time_to_die);
	printf("Tiempo para comer: %d\n", cfg->time_to_eat);
	printf("Tiempo para dormir: %d\n", cfg->time_to_sleep);
	if (cfg->has_limit)
		printf("Número de veces que deben comer: %d\n", cfg->must_eat);
	else
		printf("Sin límite de comidas.\n");
}

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (parse_args(argc, argv, &cfg))
	{
		write(2, "Error: argumentos inválidos\n", 28);
		return (1);
	}
	print_config(&cfg);
	return (0);
}