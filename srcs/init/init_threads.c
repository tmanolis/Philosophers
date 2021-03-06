/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:51:10 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/20 11:37:12 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_threads(t_data *data)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = data->nb_philo;
	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * nb_philo);
	if (!data->thread)
		return (FAILURE);
	data->initial_time = get_time();
	while (i < nb_philo)
	{
		if (pthread_create(&data->thread[i], NULL, \
		&routine, &data->philo[i]) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
