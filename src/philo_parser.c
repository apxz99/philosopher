/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:33:32 by sarayapa          #+#    #+#             */
/*   Updated: 2026/04/09 20:58:57 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i <= ac)
		{
			if (!is_valid_number(av[i++]))
				return (1);
		}
	}
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
