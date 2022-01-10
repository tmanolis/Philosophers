/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:20:23 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/10 19:11:50 by tmanolis         ###   ########.fr       */
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

int	init_philo(t_data *data)
{
	int i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (FAILURE);
	if (init_mutex_forks(data, data->nb_philo) == FAILURE)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->fork[(i + 1) % data->nb_philo];
		data->philo[i].right_fork = &data->fork[i];
		data->philo[i].needs_to_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].is_dead = false;
		data->philo[i].data = data;
		i++;
	}
	return (SUCCESS);
}
