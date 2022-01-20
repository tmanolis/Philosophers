/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:51:19 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/20 14:11:30 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_errors(char *str)
{
	printf("%sError : %s\n%s", RED, str, RESET);
}

int	check_args_are_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				print_errors("Args must be only composed by digits.\n");
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_int_are_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_strlen(argv[i]) > 11)
		{
			print_errors("Args can't be superior at INT_MAX\n");
			return (FAILURE);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			print_errors("Args can't be inferior at 0.\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_errors(int argc, char **argv)
{
	if (check_int_are_valid(argc, argv) == FAILURE)
		return (FAILURE);
	if (check_args_are_digits(argc, argv) == FAILURE)
		return (FAILURE);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		print_errors("<Number_of_times_each_philosopher_must_eat>\
		must be superior at 0. If you don't want\
		to set up a mimimum don't add a 5th arg.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
