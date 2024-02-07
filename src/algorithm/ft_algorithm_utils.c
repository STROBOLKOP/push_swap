/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:38 by elias             #+#    #+#             */
/*   Updated: 2024/02/07 16:32:38 by efret            ###   ########.fr       */
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

void	ft_exec_rot_a(t_stack *stack, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			(ft_stack_rot(stack), ft_printf("ra\n"));
	else
		while (rot_inst++)
			(ft_stack_rev_rot(stack), ft_printf("rra\n"));
}

void	ft_exec_rot_b(t_stack *stack, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			(ft_stack_rot(stack), ft_printf("rb\n"));
	else
		while (rot_inst++)
			(ft_stack_rev_rot(stack), ft_printf("rrb\n"));
}

void	ft_rot_smallest_top(t_stack *stack)
{
	size_t	pos_smallest;
	int		rot_inst;

	pos_smallest = ft_smallest_pos(stack);
	rot_inst = ft_rot_instr(stack->len, pos_smallest);
	ft_exec_rot_a(stack, rot_inst);
}

int	ft_check_ordered(t_stack *stack)
{
	size_t			pos_smallest;
	t_stack_node	*smallest;
	t_stack_node	*iter;

	if (!stack)
		return (-1);
	pos_smallest = ft_smallest_pos(stack);
	iter = stack->head;
	while (pos_smallest-- >= 1)
		iter = iter->next;
	smallest = iter;
	while (iter->next != smallest)
	{
		if (iter->value > iter->next->value)
			return (0);
		iter = iter->next;
	}
	return (1);
}
