/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:20:50 by david             #+#    #+#             */
/*   Updated: 2025/04/18 18:27:01 by david            ###   ########.fr       */
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

int	validate_and_convert(char **nums, int count, int *values)
{
	int	i;

	i = 0;
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
	return (0);
}