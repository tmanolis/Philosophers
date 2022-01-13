/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:12:25 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/13 15:57:08 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleep_and_think(t_philo *philo)
{
	display(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	display(philo, "is thinking");
	usleep(10);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->last_meal = philo->data->initial_time;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	if (philo->id % 2)
		usleep(30000);
	while (check_is_alive(philo) == SUCCESS)
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (0);
}