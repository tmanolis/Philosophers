/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:20:23 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 16:59:29 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex_forks(t_data *data)
{
	int i;

	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (SUCCESS);
}

int	init_philo(t_data *data)
{
	int i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (FAILURE);
	if (init_mutex_forks(data) == FAILURE)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].is_dead = false;
		data->philo[i].needs_to_eat = 0;
		i++;
	}
	return (SUCCESS);
}
