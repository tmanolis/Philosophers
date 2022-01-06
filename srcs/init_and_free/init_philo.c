/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:51:10 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/06 18:49:54 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_data *data)
{
	int i;
	int	nb_philo;
	
	i = 0;
	nb_philo = data->nb_philo;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * nb_philo);
	while (i < nb_philo)
	{
		if (pthread_create(&data->philo[i], NULL, &routine, NULL) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
