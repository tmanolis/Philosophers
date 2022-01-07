/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:39:55 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 14:58:34 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_args(int argc, char **argv, t_data *data)
{
	(void)argc;
	data->nb_philo = atoi(argv[1]);
	printf("nb philo: %d\n", data->nb_philo);
	if (init_philo(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
