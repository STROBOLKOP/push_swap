/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_solve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:08:30 by efret             #+#    #+#             */
/*   Updated: 2024/02/07 16:41:05 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_solve3(t_stacks *stacks)
{
	if (!ft_check_ordered(stacks->a))
		(ft_stacks_sa(stacks), ft_printf("sa\n"));
	ft_rot_smallest_top(stacks->a);
}

void	ft_simplest_solve(t_stacks *stacks)
{
	if (!ft_check_ordered(stacks->a))
	{
		while (stacks->a->len > 3)
			(ft_stacks_pb(stacks), ft_printf("pb\n"));
		if (DEBUG) ft_display_stacks(stacks);
		if (!ft_check_ordered(stacks->a))
			(ft_stacks_sa(stacks), ft_printf("sa\n"));
		while (stacks->b->len)
		{
			ft_insert_cheapest(stacks);
			if (DEBUG) ft_display_stacks(stacks);
		}
	}
	ft_rot_smallest_top(stacks->a);
	if (DEBUG) ft_display_stacks(stacks);
}
