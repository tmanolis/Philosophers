/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:12:25 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/11 16:44:23 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_death(t_philo *philo, long int last_meal_time)
{
		if (last_meal_time > philo->data->time_to_die)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			philo->is_dead = true;
			return (FAILURE);
		}
		else
			return (SUCCESS);
}

void	philo_eat(t_philo *philo)
{
	long int	actual_time;
	
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	actual_time = get_time();
	if (philo->last_meal == 0)
	{
		if (check_death(philo, actual_time - philo->data->initial_time) == FAILURE)
			return ;
	}
	else
	{
		if (check_death(philo, actual_time - philo->last_meal) == FAILURE)
			return ;
	}
	printf("%ld ms : Philo %d is eating\n", (actual_time - philo->data->initial_time), philo->id);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_meal = actual_time;
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(15);
	philo_eat(philo);
	return (0);
}