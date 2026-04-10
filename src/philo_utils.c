/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:12:32 by sarayapa          #+#    #+#             */
/*   Updated: 2026/04/10 12:21:24 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_atoi(const char *n)
{
	int		neg;
	long	i;
	int		res;

	i = 0;
	res = 0;
	neg = 1;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '-' || n[i] == '+')
		neg = ',' - n[i++];
	while (ft_isdigit(n[i]) && n[i])
	{
		res = (res * 10) + (n[i] - '0');
		i++;
	}
	return (res * neg);
}

long    get_time_ms(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int is_philo_dead_eat(t_philo *philo)
{
	if(get_time_ms() - philo->last_time >= philo->time_to_dead)
	{
		philo->data->is_dead = 1;
		printf("%d is dead.\n", philo->id);
		return (1);
	}
	return (0);
}

void	ms_sleep(long time_ms)
{
	long	start_time;

	start_time = get_time_ms();
	while(get_time_ms() - start_time < time_ms )
		usleep(500);
}