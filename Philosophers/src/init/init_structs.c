/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:36:21 by david             #+#    #+#             */
/*   Updated: 2025/04/18 16:40:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_config *cfg)
{
	int	i;

	cfg->forks = malloc(sizeof(pthread_mutex_t) * cfg->num_philos);
	if (!cfg->forks)
		return (1);
	i = 0;
	while (i < cfg->num_philos)
	{
		if (pthread_mutex_init(&cfg->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&cfg->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&cfg->death_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_philo **philos, t_config *cfg)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * cfg->num_philos);
	if (!*philos)
		return (1);
	i = 0;
	while (i < cfg->num_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].times_eaten = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].cfg = cfg;
		(*philos)[i].left_fork = &cfg->forks[i];
		(*philos)[i].right_fork = &cfg->forks[(i + 1) % cfg->num_philos];
		i++;
	}
	return (0);
}
