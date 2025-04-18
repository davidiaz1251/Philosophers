/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:25 by david             #+#    #+#             */
/*   Updated: 2025/04/18 18:07:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_philos(t_philo *philos, t_config *cfg)
{
	int	i;

	i = 0;
	while (i < cfg->num_philos)
	{
		printf("Filósofo %d\n", philos[i].id);
		printf("  Left fork : %p\n", (void *)philos[i].left_fork);
		printf("  Right fork: %p\n", (void *)philos[i].right_fork);
		printf("  Veces comido: %d\n", philos[i].times_eaten);
		printf("  Última comida: %ld\n\n", philos[i].last_meal);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_philo		*philos;

	if (parse_args(argv, &cfg))
		return (printf("Error: argumentos inválidos\n"), 1);
	if (init_forks(&cfg))
		return (printf("Error: al crear mutex de forks\n"), 1);
	if (init_philos(&philos, &cfg))
		return (printf("Error: al crear filósofos\n"), 1);
    if (start_simulation(philos, &cfg))
		return (printf("Error: al iniciar la simulación\n"), 1);
	// print_philos(philos, &cfg);
	free_all(philos, &cfg);
	return (0);
}
