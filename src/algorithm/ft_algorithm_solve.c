/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_solve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:08:30 by efret             #+#    #+#             */
/*   Updated: 2024/02/06 15:09:03 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_solve3(t_stacks *stacks)
{
	if (!ft_check_ordered(stacks->a))
		ft_stacks_sa(stacks);
	ft_rot_smallest_top(stacks->a);
}

void	ft_simplest_solve(t_stacks *stacks)
{
	while (stacks->a->len > 3)
	{
		ft_rot_smallest_top(stacks->a);
		ft_stacks_pb(stacks);
	}
	ft_solve3(stacks);
	while (stacks->b->len)
	{
		ft_stacks_pa(stacks);
	}
}
