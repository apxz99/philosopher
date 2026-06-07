/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:55:43 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 19:11:04 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_full(t_philo *philo)
{
	int	i;

	if (philo->num_times_to_eat == -1)
		return (0);
	i = 0;
	while (i < philo->total_philo)
	{
		pthread_mutex_lock(philo->meal_lock);
		if (philo->data->philos[i].meals_eaten < philo->num_times_to_eat)
		{
			pthread_mutex_unlock(philo->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	return (1);
}

int	is_simulation_stop(t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(philo->dead_lock);
	tmp = *(philo->dead);
	pthread_mutex_unlock(philo->dead_lock);
	if (tmp)
		return (1);
	return (is_full(philo));
}

int	is_valid_cal(char *str)
	{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_death(t_philo *philo)
{
	size_t	now;

	now = get_current_time();
	pthread_mutex_lock(&philo->data->print_lock);
	pthread_mutex_lock(philo->dead_lock);
	*(philo->dead) = 1;
	pthread_mutex_unlock(philo->dead_lock);

	printf("%ld %d died\n", now - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_lock);
}

int	check_death(t_main *main, int i)
{
	size_t	now;
	
	now = get_current_time();
	pthread_mutex_lock(&main->meal_lock);
	if (now - main->philos[i].last_meal > main->philos[i].time_to_die)
	{
		pthread_mutex_unlock(&main->meal_lock);
		pthread_mutex_lock(&main->dead_lock);
		main->dead_flag = 1;
		pthread_mutex_unlock(&main->dead_lock);
		print_death(&main->philos[i]);
		return (1);
	}
	pthread_mutex_unlock(&main->meal_lock);
	return (0);
}
