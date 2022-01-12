/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:39 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/12 13:53:24 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	data = (t_data){0};
	
	if (argc == 5 || argc == 6)
	{
		if (get_args(argc, argv, &data) == FAILURE)
			return (FAILURE);
	}
	else
		return (FAILURE);
	init_threads(&data);
	check_death(&data);
	printf("I AM MUEERTEEEEEEEEEEEEEEEEEEEEEEEEE\n");
	join_threads(&data);
	free4yourlife(&data);
	return (0);
}
