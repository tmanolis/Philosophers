/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:51:10 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/06 18:20:44 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_data *data)
{
	int i;
	
	i = 0;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * 4);
	while (i < 4)
	{
		if (pthread_create(&data->philo[i], NULL, &routine, NULL) != 0)
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(data->philo[i], NULL) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
