/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:29:45 by sarayapa          #+#    #+#             */
/*   Updated: 2026/04/10 11:17:59 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	//philo_eat
	pthread_mutex_lock(&philo->left_fork.fork_mut);
	pthread_mutex_lock(&philo->right_fork.fork_mut);
	ms_sleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork.fork_mut);
	pthread_mutex_unlock(&philo->right_fork.fork_mut);
	philo->last_time = get_time_ms();
	printf("philo_eated");
}

void	philo_sleep(t_philo *philo)
{
	printf("philo_sleep");
	ms_sleep(philo->time_to_sleep);
	philo->last_time = get_time_ms();

}

void	philo_think(t_philo *philo)
{
	printf("philo_think");
	ms_sleep(philo->time_to_eat);
	philo->last_time = get_time_ms();

}