/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:36:48 by david             #+#    #+#             */
/*   Updated: 2025/04/18 16:36:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int has_died(t_philo *philo)
{
    long time_now;

    pthread_mutex_lock(&philo->cfg->death_mutex);
    time_now = get_timestamp_ms();
    if (time_now - philo->last_meal > philo->cfg->time_to_die)
    {
        if (!philo->cfg->stop_simulation)
        {
            philo->cfg->stop_simulation = 1;
            pthread_mutex_lock(&philo->cfg->print_mutex);
            printf("%ld %d died\n", time_now - philo->cfg->start_time, philo->id);
            pthread_mutex_unlock(&philo->cfg->print_mutex);
        }
        pthread_mutex_unlock(&philo->cfg->death_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->cfg->death_mutex);
    return (0);
}

static int all_philos_full(t_philo *philos)
{
    int i;
    int count;
    t_config *cfg;

    cfg = philos[0].cfg;
    if (!cfg->has_limit)
        return (0);
    count = 0;
    i = 0;
    while (i < cfg->num_philos)
    {
        if (philos[i].times_eaten >= cfg->must_eat)
            count++;
        i++;
    }
    if (count == cfg->num_philos)
    {
        pthread_mutex_lock(&cfg->death_mutex);
        cfg->stop_simulation = 1;
        pthread_mutex_unlock(&cfg->death_mutex);
        return (1);
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_philo *philos;
    t_config *cfg;
    int i;

    philos = (t_philo *)arg;
    cfg = philos[0].cfg;
    while (!cfg->stop_simulation)
    {
        i = 0;
        while (i < cfg->num_philos && !cfg->stop_simulation)
        {
            if (has_died(&philos[i]))
                break;
            i++;
        }
        if (all_philos_full(philos))
        {
            break;
        }
        usleep(500);
    }
    return (NULL);
}
