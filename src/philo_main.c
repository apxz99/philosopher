/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:54:53 by sarayapa          #+#    #+#             */
/*   Updated: 2026/04/10 12:59:05 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data data;
	if (!parse_args(ac, av))
		return (1);
	init_data(ac, av, &data);
	create_threads(&data);
	return (0);
}
void init_data(int ac, char **av, t_data *data)
{
	int		f;
	int		p;

	f = 0;
	p = 0;
	data->philo_count = ft_atoi(av[1]);
	data->eat_count = -1;
	if(ac == 6)
		data->eat_count = ft_atoi(av[5]);
	data->forks = malloc(sizeof(t_fork) * data->philo_count);
	if(!data->philo)
		return;
	while (f < data->philo_count)
		pthread_mutex_init(&data->forks[f++].fork_mut, NULL);
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	if(!data->philo)
		return;
	while (p < data->philo_count)
	{
		data->philo[p].id  = p;
		data->philo[p].left_fork  = data->forks[p];
		data->philo[p].right_fork = data->forks[(p + 1 % data->philo_count)];
		data->philo[p].data = data;
		data->philo[p].time_to_dead = ft_atoi(av[2]);
		data->philo[p].time_to_eat = ft_atoi(av[3]);
		data->philo[p].time_to_sleep = ft_atoi(av[4]);
		p++;
	}
}

void create_threads(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->philo_count)
	{
		pthread_create(
			&data->philo[i].thread,
			NULL,
			&loop_philo,
			&data->philo[i]);
		i++;
	}
}

void *loop_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->data->start_time = get_time_ms();
	if(philo->id % 2 != 0)
		ms_sleep(500 * 2);
	while(!is_philo_dead_eat(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
