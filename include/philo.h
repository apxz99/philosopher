/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:39 by sarayapa          #+#    #+#             */
/*   Updated: 2026/04/10 12:59:05 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_fork
{
	pthread_mutex_t fork_mut;
}	t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_fork		left_fork;
	t_fork		right_fork;
	long		last_time;
	int			time_to_dead;
	int			time_to_eat;
	int			time_to_sleep;
	t_data 		*data;
}	t_philo;

typedef struct s_data
{
	int		philo_count;
	int		eat_count;
	int		is_dead;
	pthread_mutex_t	is_dead_mut;
	pthread_mutex_t	is_eat_mut;
	t_fork	*forks;
	t_philo	*philo;
	long int	start_time;
}	t_data;

int		parse_args(int ac, char **av);
int		args_fail_checker(int ac, char **av);
int		is_valid_number(const char *str);
int		ft_atoi(const char *c);
int		ft_isdigit(int n);
void	init_data(int ac, char **av, t_data *data);
void	create_threads(t_data *data);
void	*loop_philo(void *arg);
long    get_time_ms(void);
int		is_philo_dead_eat(t_philo *philo);
void	ms_sleep(long time_ms);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

#endif