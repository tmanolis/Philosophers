/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free4yourlife.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:53:11 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 14:58:21 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free4yourlife(t_data *data)
{
	free(data->thread);
	free(data->philo);
}
