/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:39 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 16:01:31 by tmanolis         ###   ########.fr       */
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
	
	data = (t_data){0};
	
	if (argc >= 5 && argc < 7)
	{
		if (get_args(argc, argv, &data) == FAILURE)
			return (FAILURE);
	}
	else
		return (FAILURE);
	init_threads(&data);
	join_threads(&data);
	free4yourlife(&data);
	return (0);
}
