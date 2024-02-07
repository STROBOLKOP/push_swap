/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:38 by elias             #+#    #+#             */
/*   Updated: 2024/02/07 13:09:38 by efret            ###   ########.fr       */
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

void	ft_exec_rot(t_stack *stack, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			ft_stack_rot(stack);
	else
		while (rot_inst++)
			ft_stack_rev_rot(stack);
}

void	ft_rot_smallest_top(t_stack *stack)
{
	size_t	pos_smallest;
	int		rot_inst;

	pos_smallest = ft_smallest_pos(stack);
	rot_inst = ft_rot_cost(stack->len, pos_smallest);
	ft_exec_rot(stack, rot_inst);
	if (rot_inst >= 0)
		while (rot_inst--)
			ft_printf("ra\n");
	else
		while (rot_inst++)
			ft_printf("rra\n");
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
