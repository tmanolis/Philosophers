/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:54 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/20 14:42:31 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	update_last_meal(t_data *data, long int actual_time, int i)
{
	long int	last_meal_time;

	pthread_mutex_lock(&data->mutex_meal);
	last_meal_time = actual_time - data->philo[i].last_meal;
	pthread_mutex_unlock(&data->mutex_meal);
	return (last_meal_time);
}

void	kill_philo(t_data *data, long int actual_time, int i)
{
	pthread_mutex_lock(&data->mutex_death);
	data->is_dead = true;
	pthread_mutex_unlock(&data->mutex_death);
	printf("%s%ld ms	: Philo %d died\n%s",
		RED, actual_time - data->initial_time, data->philo[i].id, RESET);
}

int	philos_finish_eating(t_data *data)
{
	pthread_mutex_lock(&data->mutex_meal);
	if (data->philos_need_to_eat > 0)
	{
		pthread_mutex_unlock(&data->mutex_meal);
		return (FAILURE);
	}
	pthread_mutex_unlock(&data->mutex_meal);
	return (SUCCESS);
}

void	check_death_without_meals(t_data *data)
{
	int			i;
	long int	actual_time;
	long int	last_meal_time;

	usleep(30000);
	i = 0;
	while (1)
	{
		actual_time = get_time();
		last_meal_time = update_last_meal(data, actual_time, i);
		if (last_meal_time > data->time_to_die)
		{
			kill_philo(data, actual_time, i);
			return ;
		}
		i++;
		if (i == (data->nb_philo - 1))
			i = 0;
		usleep(10);
	}
}

void	check_death_with_meals(t_data *data)
{
	int			i;
	long int	actual_time;
	long int	last_meal_time;

	usleep(30000);
	i = 0;
	while (1 && philos_finish_eating(data) == FAILURE)
	{
		actual_time = get_time();
		last_meal_time = update_last_meal(data, actual_time, i);
		if (last_meal_time > data->time_to_die
			&& philos_finish_eating(data) == FAILURE)
		{
			kill_philo(data, actual_time, i);
			return ;
		}
		i++;
		if (i == (data->nb_philo - 1))
			i = 0;
		usleep(10);
	}
	return ;
}
