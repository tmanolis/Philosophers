/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:39 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/06 18:47:00 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine()
{
	printf("je do the routine\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	
	int i;
	data = (t_data){0};
	
	if (argc > 1)
	{
		if (get_args(argc, argv, &data) == FAILURE)
			return (FAILURE);
	}
	init_philo(&data);
	i = 0;
	while (i < 4)
	{
		if (pthread_join(data.philo[i], NULL) != 0)
			return (FAILURE);
		i++;
	}
	free4yourlife(&data);
	return (0);
}
