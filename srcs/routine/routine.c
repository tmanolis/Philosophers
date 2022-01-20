/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:12:25 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/20 13:52:19 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo_routine(t_philo *philo)
{
	display(philo, "has taken a fork", WHITE);
	usleep(philo->data->time_to_die * 1000);
	printf("%s%d ms : Philo %d died\n%s",
		RED, philo->data->time_to_die, philo->id, RESET);
}

void	init_meal_and_protect_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->last_meal = philo->data->initial_time;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	if (philo->id % 2)
		usleep(30000);
}

void	philo_sleep_and_think(t_philo *philo)
{
	display(philo, "is sleeping", BLUE);
	usleep(philo->data->time_to_sleep * 1000);
	display(philo, "is thinking", PURPLE);
	usleep(100);
}

void	routine_with_meals(t_philo *philo)
{
	while (check_is_alive(philo) == SUCCESS && (philo->needs_to_eat > 0))
	{
		philo_eat(philo);
		if (philo->needs_to_eat > 0)
			philo_sleep_and_think(philo);
	}
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->data->philos_need_to_eat--;
	pthread_mutex_unlock(&philo->data->mutex_meal);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		one_philo_routine(philo);
		return (0);
	}
	init_meal_and_protect_forks(philo);
	if (philo->needs_to_eat == 0)
	{
		while (check_is_alive(philo) == SUCCESS)
		{
			philo_eat(philo);
			philo_sleep_and_think(philo);
		}
		return (0);
	}
	else
	{
		routine_with_meals(philo);
		return (0);
	}
}
