/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:38 by elias             #+#    #+#             */
/*   Updated: 2024/02/05 17:53:31 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	ft_smallest_pos(t_stack *stack)
{
	t_stack_node	*smallest;
	t_stack_node	*iter;
	size_t			pos_iter;
	size_t			res;

	smallest = stack->head;
	res = 0;
	iter = stack->head->next;
	pos_iter = 1;
	while (iter != stack->head)
	{
		if (iter->value < smallest->value)
		{
			smallest = iter;
			res = pos_iter;
		}
		iter = iter->next;
		pos_iter++;
	}
	return (res);
}

void	ft_rot_smallest_top(t_stack *stack)
{
	size_t	pos_smallest;

	pos_smallest = ft_smallest_pos(stack);
	if (pos_smallest <= stack->len >> 1)
	{
		while (pos_smallest-- >= 1)
		{
			ft_stack_rot(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		pos_smallest = stack->len - pos_smallest;
		while (pos_smallest-- >= 1)
		{
			ft_stack_rev_rot(stack);
			ft_printf("rra\n");
		}
	}
}

void	ft_simplest_solve(t_stacks *stacks)
{
	while (stacks->a->len)
	{
		ft_rot_smallest_top(stacks->a);
		ft_stacks_pb(stacks);
	}
	while (stacks->b->len)
	{
		ft_stacks_pa(stacks);
	}
}
