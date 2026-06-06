/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:54:53 by sarayapa          #+#    #+#             */
/*   Updated: 2026/06/06 22:36:58 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	main;

	if (parse_args(ac, av))
		return (1);
	if (init_data(&main, ac, av) == 1)
		return (1);
	if(philo_loop())
		return(1);
}
