/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:29:56 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/18 12:21:51 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(char *str)
{
	int			i;
	int			j;
	long int	value;

	i = 0;
	j = 0;
	value = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	if (j == 1)
		return (value * -1);
	else
		return (value);
}
