/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:12:25 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/10 18:16:34 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	long int	actual_time;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	actual_time = get_time();
	printf("%ld : Philo %d is eating\n", (actual_time - philo->data->initial_time), philo->id);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(10);
	philo_eat(philo);
	return (0);
}