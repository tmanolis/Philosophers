/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:54 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/14 14:25:26 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_is_alive(t_philo *philo)
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

void	check_death(t_data *data)
{
	int			i;
	long int	actual_time;
	long int	last_meal_time;

	usleep((data->time_to_die * 1000) / 2);
	i = 0;
	while (1)
	{
		actual_time = get_time();
		pthread_mutex_lock(&data->mutex_meal);
		last_meal_time = actual_time - data->philo[i].last_meal;
		pthread_mutex_unlock(&data->mutex_meal);
		if (last_meal_time > data->time_to_die)
		{
			// printf("actual time : %ld\nlast_meal : %ld\ndiff : %ld\n", actual_time, data->philo[i].last_meal, last_meal_time);
			pthread_mutex_lock(&data->mutex_death);
			data->is_dead = true;
			pthread_mutex_unlock(&data->mutex_death);
			printf("%s%ld ms	: Philo %d died\n%s", 
			RED, actual_time - data->initial_time, data->philo[i].id, RESET);
			return ;
		}
		i++;
		if (i == (data->nb_philo - 1))
			i = 0;
		usleep(10);
	}
}
