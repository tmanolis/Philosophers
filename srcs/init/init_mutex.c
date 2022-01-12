/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:06:00 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/12 13:36:07 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex_forks(t_data *data, int nb_philo)
{
	int i;

	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!data->fork)
		return (FAILURE);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (SUCCESS);
}

int	init_mutex(t_data *data)
{
	if (init_mutex_forks(data, data->nb_philo) == FAILURE)
		return (FAILURE);
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_death, NULL);
	return (SUCCESS);
}
