/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:20:23 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/13 17:50:05 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_data *data)
{
	int i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		if (data->nb_philo > 1)
			data->philo[i].left_fork = &data->fork[(i + 1) % data->nb_philo];
		data->philo[i].right_fork = &data->fork[i];
		data->philo[i].needs_to_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].data = data;
		i++;
	}
	return (SUCCESS);
}
