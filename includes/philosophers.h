/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:29 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/10 18:12:17 by tmanolis         ###   ########.fr       */
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
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
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