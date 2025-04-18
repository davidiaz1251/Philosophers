/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:43 by david             #+#    #+#             */
/*   Updated: 2025/04/18 16:35:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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