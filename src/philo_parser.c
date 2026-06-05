/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:33:32 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/05 13:35:28 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av)
{
	int i;

	if (ac != 5 && ac != 6)
		return (1);
	i = 1;
	while(i < ac)
	{
		if(!is_valid_cal(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_forks(t_main *main, int n)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!main->forks)
	{
		free(main->philos);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	return (0);
}

void    init_philos(t_main *main, int n, int ac, char **av)
{
	int i;

	i = 0;
	while (i < n)
	{
		main->philos[i].id = i + 1;
		main->philos[i].is_eating = 0;
		main->philos[i].meals_eaten = 0;
		main->philos[i].total_philo = n;
		main->philos[i].time_to_die = ft_atoi(av[2]);
		main->philos[i].time_to_eat = ft_atoi(av[3]);
		main->philos[i].time_to_sleep = ft_atoi(av[4]);
		main->philos[i].num_times_to_eat = -1;
		if (ac == 6)
			main->philos[i].num_times_to_eat = ft_atoi(av[5]);
		main->philos[i].start_time = get_time_ms();
		main->philos[i].last_meal = get_time_ms();
		main->philos[i].dead = &main->dead_flag;
		main->philos[i].dead_lock = &main->dead_lock;
		main->philos[i].meal_lock = &main->meal_lock;
		main->philos[i].r_fork = &main->forks[i];
		main->philos[i].l_fork = &main->forks[(i + 1) % n];
		i++;
	}
}

int	init_data(t_main *main, int ac, char **av)
{
	int	n;

	n = ft_atoi(av[1]);
	main->dead_flag = 0;
	pthread_mutex_init(&main->dead_lock, NULL);
	pthread_mutex_init(&main->meal_lock, NULL);
	main->philos = malloc(sizeof(t_philo) * n);
	if (!main->philos)
		return (1);
	if (init_forks(main, n))
		return (1);
	init_philos(main, n, ac, av);
	return (0);
}
