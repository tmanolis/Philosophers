/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:29 by tmanolis          #+#    #+#             */
/*   Updated: 2022/01/17 14:39:11 by tmanolis         ###   ########.fr       */
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

# define BLUE "\033[1;36m"
# define GREEN "\033[0;32m"
# define PURPLE "\033[1;35m"
# define RED "\033[1;31m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int				needs_to_eat;
	long int		last_meal;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philos_need_to_eat;
	long int		initial_time;
	bool			is_dead;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_death;
}				t_data;


// INIT--- check_errors
int			check_errors(int argc, char **argv);
// INIT--- get_args
int			get_args(int argc, char **argv, t_data *data);
// INIT--- init_mutex
int			init_mutex_forks(t_data *data, int nb_philo);
int			init_mutex(t_data *data);
// INIT--- init_philo
int			init_philo(t_data *data);
// INIT --- init_threads
int			init_threads(t_data *data);
// ROUTINE --- check_death
void		check_death_without_meals(t_data *data);
void		check_death_with_meals(t_data *data);
// ROUTINE --- check_is_alive
int			check_is_alive(t_philo *philo);
// ROUTINE --- display
long int	display(t_philo *philo, char *str, char *color);
// ROUTINE --- philo_eat
void		philo_eat(t_philo *philo);
// ROUTINE --- routine
void		*routine(void *arg);
// UTILS --- free4yourlife
void		free4yourlife(t_data *data);
// UTILS --- ft_atoi
int			ft_atoi(char *str);
// UTILS --- ft_isdigit.c
int			ft_isdigit(int c);
// UTILS --- get_time
long int	get_time(void);
// UTILS --- join_threads
int			join_threads(t_data *data);


#endif