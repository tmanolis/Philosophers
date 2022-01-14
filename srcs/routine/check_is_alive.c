/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:53:05 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/14 18:53:36 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_death);
	if (philo->data->is_dead == true)
	{
		pthread_mutex_unlock(&philo->data->mutex_death);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->data->mutex_death);
	return (SUCCESS);
}
