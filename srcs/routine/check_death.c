/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:54 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/11 19:42:14 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_death(t_philo *philo)
{
	long int	actual_time;
	long int	last_meal_time;

	actual_time = get_time();
	if (philo->last_meal == 0)
		last_meal_time = actual_time - philo->data->initial_time;
	else
		last_meal_time = actual_time - philo->last_meal;
	if (last_meal_time > philo->data->time_to_die)
	{
		philo->is_dead = true;
		printf("%ld ms : Philo %d died\n", (actual_time - philo->data->initial_time), philo->id);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}
