/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:08:11 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/14 14:29:33 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	display(t_philo *philo, char *str, char *color)
{
	long int	actual_time;

	actual_time = get_time();
	if (check_is_alive(philo) == SUCCESS)
	{
		pthread_mutex_lock(&philo->data->mutex_print);
		printf("%s%ld ms	: Philo %d %s\n%s", 
		color, (actual_time - philo->data->initial_time), philo->id, str, RESET);
		pthread_mutex_unlock(&philo->data->mutex_print);
	}
	return (actual_time);
}
