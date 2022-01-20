/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free4yourlife.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:53:11 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/20 15:44:49 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_mutex_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free(data->fork);
}

void	free_mutex(t_data *data)
{
	free_mutex_fork(data);
	pthread_mutex_destroy(&data->mutex_meal);
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_death);
}

void	free4yourlife(t_data *data)
{
	free(data->thread);
	free(data->philo);
	free_mutex(data);
}
