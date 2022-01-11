/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:29 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/11 19:17:21 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct s_philo
{
	int				id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int				needs_to_eat;
	long int		last_meal;
	bool			is_dead;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long int		initial_time;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
}				t_data;


// INIT--- get_args
int		get_args(int argc, char **argv, t_data *data);
// INIT--- init_philo
int		init_philo(t_data *data);
// INIT --- init_threads
int		init_threads(t_data *data);
// ROUTINE --- check_death
int		check_death(t_philo *philo);
// ROUTINE --- routine.c
void	*routine(void *arg);
// UTILS --- free4yourlife
void	free4yourlife(t_data *data);
// UTILS --- ft_atoi.c
int		ft_atoi(char *str);
// UTILS --- ft_isdigit.c
int		ft_isdigit(int c);
// UTILS --- get_time.c
long int	get_time(void);
// UTILS --- join_threads.c
int		join_threads(t_data *data);


#endif