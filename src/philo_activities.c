/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:29:45 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 19:25:45 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);

	if (is_simulation_stop(philo))
	{
		pthread_mutex_unlock(fork);
		return (1);
	}
	safe_print("has taken a fork", philo);
	return (0);
}

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	else
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	pthread_mutex_lock(first);
	if (take_fork(philo, first))
		return;
	if (take_fork(philo, second))
	{
		pthread_mutex_unlock(first);
		return;
	}
}

void	ft_eating(t_philo *philo)
{
	ft_take_fork(philo);
	if (is_simulation_stop(philo))
		return;
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 1;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	safe_print("is eating", philo);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

void	ft_sleeping(t_philo *philo)
{
	safe_print("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	safe_print("is thinking", philo);
}
