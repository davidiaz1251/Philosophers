/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:08 by david             #+#    #+#             */
/*   Updated: 2025/04/18 18:21:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 

# define INT_MAX 2147483647

/* ----------- ESTRUCTURAS ----------- */

typedef struct s_config
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				has_limit;
	long			start_time;
	int				stop_simulation;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*forks;
}	t_config;

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_config		*cfg;
}	t_philo;

/* ----------- FUNCIONES ----------- */

/* init */
int		parse_args(char **argv, t_config *cfg);
int		init_philos(t_philo **philos, t_config *cfg);
int	    init_forks(t_config *cfg);

/* utils */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_timestamp_ms(void);
void	ft_usleep(int ms);
void	print_status(t_philo *philo, const char *msg);
void	free_split(char **arr);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int	    validate_and_convert(char **nums, int count, int *values);


/* cleanup */
void	free_all(t_philo *philos, t_config *cfg);

int		start_simulation(t_philo *philos, t_config *cfg);
void	*philo_routine(void *arg);

void	*monitor_routine(void *arg);

#endif