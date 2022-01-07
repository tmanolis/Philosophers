/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free4yourlife.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:53:11 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 17:47:31 by tmanolis         ###   ########.fr       */
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

void	free4yourlife(t_data *data)
{
	free(data->thread);
	free(data->philo);
	free_mutex_fork(data);
}
