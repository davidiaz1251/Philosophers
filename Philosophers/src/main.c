/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:25 by david             #+#    #+#             */
/*   Updated: 2025/04/18 22:05:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	free_all(philos, &cfg);
	return (0);
}
