/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:54 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/11 22:34:34 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_death(t_philo *philo)
{
	long int	actual_time;
	long int	last_meal_time;

	actual_time = get_time();
	last_meal_time = actual_time - philo->last_meal;
	if (last_meal_time > philo->data->time_to_die)
	{
		philo->data->is_dead = true;
		printf("%ld ms : Philo %d died\n", (actual_time - philo->data->initial_time), philo->id);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

// void	check_death(t_data *data)
// {
	
// }