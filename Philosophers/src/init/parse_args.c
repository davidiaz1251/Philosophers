/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:36:35 by david             #+#    #+#             */
/*   Updated: 2025/04/18 17:55:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_number(const char *str)
{
    int i = 0;

    if (!str || str[0] == '\0')
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
static int	process_split_segment(char **tmp, char **out, int *count)
{
	int	j;

	j = 0;
	while (tmp[j])
	{
		out[*count] = ft_strdup(tmp[j]);
		if (!out[*count])
			return (1);
		(*count)++;
		j++;
		if (*count > 5)
			return (1);
	}
	return (0);
}
int	split_and_count(char **argv, char **out)
{
	int		i;
	int		count;
	char	**tmp;

	i = 1;
	count = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (-1);
		if (process_split_segment(tmp, out, &count))
		{
			free_split(tmp);
			return (-1);
		}
		free_split(tmp);
		i++;
	}
	return (count);
}

static int fill_config(char **nums, int count, t_config *cfg)
{
    int values[5];
    int i = 0;

    while (i < count)
    {
        if (!is_number(nums[i]))
            return (1);
        values[i] = ft_atoi(nums[i]);
        if (values[i] <= 0 || values[i] == -1)
            return (1);
        if (i == 0 && values[0] > 200)
            return (1);
        i++;
    }
    cfg->num_philos = values[0];
    cfg->time_to_die = values[1];
    cfg->time_to_eat = values[2];
    cfg->time_to_sleep = values[3];
    cfg->has_limit = (count == 5);
    cfg->must_eat = (count == 5) ? values[4] : -1;
    cfg->stop_simulation = 0;
    return (0);
}

int parse_args(char **argv, t_config *cfg)
{
    char *args[6];
    int count;
    int		i;

    count = split_and_count(argv, args);
    if (count < 4 || count > 5)
        return (1);
    if (fill_config(args, count, cfg))
        return (1);
    i = 0;
    while (i < count)
        free(args[i++]);
    return (0);
}
