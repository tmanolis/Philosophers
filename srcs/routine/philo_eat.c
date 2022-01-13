/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:56:36 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/13 17:25:43 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		display(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		display(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		display(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		display(philo, "has taken a fork");
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	long int	actual_time;
	
	if (check_is_alive(philo) == FAILURE)
		return ;
	lock_forks(philo);
	actual_time = display(philo, "is eating");
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->last_meal = actual_time;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	usleep(philo->data->time_to_eat * 1000);
	unlock_forks(philo);
	if (philo->needs_to_eat != 0)
		philo->needs_to_eat--;
}
