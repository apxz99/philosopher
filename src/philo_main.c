/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:54:53 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 19:09:56 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)(args);
	while (1)
	{
		if (is_full(main->philos))
			return (NULL);
		i = 0;
		while (i < main->total_philo)
		{
			if (check_death(main, i))
				return (NULL);
			i++;
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*philo_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
	if(philo->total_philo == 1)
	{
		safe_print("has taken a fork", philo);
		ft_usleep(philo->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		if (is_simulation_stop(philo))
			break ;
		ft_eating(philo);
		if (is_simulation_stop(philo))
			break ;
		ft_sleeping(philo);
		if (is_simulation_stop(philo))
			break ;
		ft_thinking(philo);
	}
	return (NULL);
}

int	ft_philo_threads(t_main *main, pthread_t *p_th)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < main->total_philo)
	{
		if (pthread_create(&p_th[i], NULL, philo_loop, &main->philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&monitor, NULL, ft_monitor, main) != 0)
		return (1);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < main->total_philo)
	{
		if (pthread_join(p_th[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_main		main;
	pthread_t	*philo_threads;

	if (parse_args(ac, av) != 0)
		return (1);
	if (init_data(&main, ac, av) != 0)
		return (1);
	philo_threads = (pthread_t *) malloc(sizeof(pthread_t) * main.total_philo);
	if (!philo_threads)
		return (1);
	if (ft_philo_threads(&main, philo_threads) != 0)
		return (1);
	return (0);
}
