/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuya <asuya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:54:53 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/07 10:29:18 by asuya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	main;
	if (parse_args(ac, av) != 0)
		return (1);
	if (init_data(&main, ac, av) != 0)
		return (1);
	//if (thread_create(&main) != 0);
}
