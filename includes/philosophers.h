/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:29 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/07 17:49:11 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define SUCCESS 1
# define FAILURE 0

typedef struct s_philo
{
	int				id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				needs_to_eat;
	bool			is_dead;	
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
}				t_data;

// MAIN 
void	*routine();
// INIT--- get_args
int		get_args(int argc, char **argv, t_data *data);
// INIT--- init_philo
int		init_philo(t_data *data);
// INIT --- init_threads
int		init_threads(t_data *data);
// UTILS --- free4yourlife
void	free4yourlife(t_data *data);
// UTILS --- ft_atoi.c
int		ft_atoi(char *str);
// UTILS --- ft_isdigit.c
int		ft_isdigit(int c);
// UTILS --- join_threads.c
int		join_threads(t_data *data);


#endif