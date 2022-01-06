/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:29 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/06 18:42:02 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define SUCCESS 1
# define FAILURE 0

# define MAUVE "\033[38;5;98m"
# define RESET "\033[0m"

typedef struct s_philo
{

}				t_philo;


typedef struct s_data
{
	pthread_t	*philo;
	int			nb_philo;

}				t_data;

// MAIN 
void	*routine();
// INIT_AND_FREE --- free4yourlife
void	free4yourlife(t_data *data);
// INIT_AND_FREE --- get_args
int		get_args(int argc, char **argv, t_data *data);
// INIT_AND_FREE --- init_philo
int		init_philo(t_data *data);
// UTILS --- ft_atoi.c
int		ft_atoi(const char *str);
// UTILS --- ft_isdigit.c
int		ft_isdigit(int c);


#endif