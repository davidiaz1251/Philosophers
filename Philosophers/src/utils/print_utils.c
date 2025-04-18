/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:38:46 by david             #+#    #+#             */
/*   Updated: 2025/04/18 16:38:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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