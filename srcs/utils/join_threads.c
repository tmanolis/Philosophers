/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:19:55 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/06 19:44:27 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	join_threads(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
