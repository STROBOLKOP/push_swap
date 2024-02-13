/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ofc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:43:30 by elias             #+#    #+#             */
/*   Updated: 2024/02/13 14:24:25 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_between_incl(int val, int min, int max)
{
	if (min <= val && val <= max)
		return (1);
	return (0);
}

int	ft_atoi_ofc(t_stacks *stacks, const char *nptr)
{
	int	sign;
	int	number;
	int	new_number;

	sign = 1;
	number = 0;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	if (!(*nptr))
		ft_exit_handler(stacks, E_INVALID_INPUT);
	while (ft_between_incl(*nptr, '0', '9'))
	{
		new_number = number * 10 + sign * (*nptr++ - '0');
		if (sign == 1 && new_number < number)
			ft_exit_handler(stacks, E_INVALID_INPUT);
		else if (sign == -1 && new_number > number)
			ft_exit_handler(stacks, E_INVALID_INPUT);
		number = new_number;
	}
	return (number);
}
