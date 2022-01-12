/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:12:25 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/12 18:27:35 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	long int	actual_time;
	
	pthread_mutex_lock(philo->left_fork);
	display(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	display(philo, "has taken a fork");
	actual_time = display(philo, "is eating");
	philo->last_meal = actual_time;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->needs_to_eat != 0)
		philo->needs_to_eat--;
}

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
	philo->last_meal = philo->data->initial_time;
	if (philo->id % 2)
		usleep(30000);
	while (check_is_alive(philo) == SUCCESS)
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (0);
}