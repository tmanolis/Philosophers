/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:39:55 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/10 14:53:31 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_time(t_data *data, int die, int eat, int sleep)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].time_to_die = die;
		data->philo[i].time_to_eat = eat;
		data->philo[i].time_to_sleep = sleep;
		i++;
	}
}

void	get_nb_needs_to_eat(t_data *data, int nb)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].needs_to_eat = nb;
		i++;
	}
}

int	get_args(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	if (init_philo(data) == FAILURE)
		return (FAILURE);
	get_time(data, ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		get_nb_needs_to_eat(data, ft_atoi(argv[5]));
	return (SUCCESS);
}
