/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:33:32 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 18:29:40 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (1);
	i = 1;
	while (i < ac)
	{
		if (!is_valid_cal(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->total_philo);
	if (!main->forks)
	{
		free(main->philos);
		return (1);
	}
	i = 0;
	while (i < main->total_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&main->forks[i]);
			free(main->forks);
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_philos(t_main *main, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < main->total_philo)
	{
		main->philos[i].id = i + 1;
		main->philos[i].is_eating = 0;
		main->philos[i].meals_eaten = 0;
		main->philos[i].total_philo = main->total_philo;
		main->philos[i].time_to_die = ft_atoi(av[2]);
		main->philos[i].time_to_eat = ft_atoi(av[3]);
		main->philos[i].time_to_sleep = ft_atoi(av[4]);
		main->philos[i].start_time = main->start_time;
		main->philos[i].num_times_to_eat = -1;
		if (ac == 6)
			main->philos[i].num_times_to_eat = ft_atoi(av[5]);
		main->philos[i].last_meal = get_current_time();
		main->philos[i].dead = &main->dead_flag;
		main->philos[i].print_lock = &main->print_lock;
		main->philos[i].dead_lock = &main->dead_lock;
		main->philos[i].meal_lock = &main->meal_lock;
		main->philos[i].r_fork = &main->forks[i];
		main->philos[i].l_fork = &main->forks[(i + 1) % main->total_philo];
		main->philos[i].data = main;
	}
}

int	init_data(t_main *main, int ac, char **av)
{
	main->start_time = get_current_time();
	main->total_philo = ft_atoi(av[1]);
	main->dead_flag = 0;
	pthread_mutex_init(&main->dead_lock, NULL);
	pthread_mutex_init(&main->meal_lock, NULL);
	pthread_mutex_init(&main->print_lock, NULL);
	main->philos = ft_calloc(sizeof(t_philo), main->total_philo);
	if (!main->philos)
		return (1);
	if (init_forks(main))
	{
		free(main->philos);
		pthread_mutex_destroy(&main->dead_lock);
		pthread_mutex_destroy(&main->meal_lock);
		pthread_mutex_destroy(&main->print_lock);
		return (1);
	}
	init_philos(main, ac, av);
	return (0);
}
