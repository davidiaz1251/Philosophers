/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:08 by david             #+#    #+#             */
/*   Updated: 2025/04/18 18:01:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

static void	philo_eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->cfg->death_mutex);
	philo->last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->cfg->death_mutex);
	print_status(philo, "is eating");
	ft_usleep(philo->cfg->time_to_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_status(philo, "is sleeping");
	ft_usleep(philo->cfg->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->cfg->death_mutex);
		if (philo->cfg->stop_simulation)
		{
			pthread_mutex_unlock(&philo->cfg->death_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->cfg->death_mutex);
		print_status(philo, "is thinking");
		philo_eat_sleep(philo);
	}
	return (NULL);
}
