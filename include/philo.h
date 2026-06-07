/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:39 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 19:11:25 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_main t_main;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				total_philo;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	t_main			*data; 
}	t_philo;

typedef struct s_main
{
	size_t			start_time;
	int				dead_flag;
	int				total_philo;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_main;

int		init_data(t_main *main, int ac, char **av);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
size_t	get_current_time(void);
int		is_valid_cal(char *str);
int		parse_args(int ac, char **av);
int		ft_usleep(size_t milliseconds);
void	ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_thinking(t_philo *philo);
void	safe_print(char *msg, t_philo *philo);
int		is_full(t_philo *philo);
int		is_simulation_stop(t_philo *philo);
int		is_valid_cal(char *str);
int		check_death(t_main *main, int i);

#endif
