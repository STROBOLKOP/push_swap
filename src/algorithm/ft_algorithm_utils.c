/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:38 by elias             #+#    #+#             */
/*   Updated: 2024/02/12 16:03:30 by efret            ###   ########.fr       */
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

size_t	ft_find_insert_pos(t_stack *stack, t_stack_node *node)
{
	size_t			pos;
	size_t			pos_smallest;
	t_stack_node	*iter;

	if (!stack->len)
		return (0);
	pos = 0;
	pos_smallest = ft_smallest_pos(stack);
	iter = stack->head;
	while (pos < pos_smallest)
	{
		iter = iter->next;
		pos++;
	}
	pos = 0;
	while (iter->rank < node->rank && pos < stack->len)
	{
		iter = iter->next;
		pos++;
	}
	if (pos_smallest > (size_t)-1 - pos)
		return (pos_smallest - (stack->len - pos));
	return ((pos_smallest + pos) % stack->len);
}
