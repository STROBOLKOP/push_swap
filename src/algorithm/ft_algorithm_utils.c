/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:38 by elias             #+#    #+#             */
/*   Updated: 2024/02/02 17:20:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rot_smallest_top(t_stack *stack)
{
	t_stack_node	*smallest;
	t_stack_node	*iter;
	size_t			pos_smallest;
	size_t			pos_iter;

	smallest = stack->head;
	pos_smallest = 0;
	iter = stack->head->next;
	pos_iter = 1;
	while (iter != stack->head)
	{
		if (iter->value < smallest->value)
		{
			smallest = iter;
			pos_smallest = pos_iter;
		}
		iter = iter->next;
		pos_iter++;
	}
	if (pos_smallest <= stack->len >> 1)
	{
		while (stack->head != smallest)
		{
			ft_stack_rot(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (stack->head != smallest)
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
