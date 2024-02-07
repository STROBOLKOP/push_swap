/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/07 13:09:32 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	while (pos++ < pos_smallest)
		iter = iter->next;
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

int	ft_rot_cost(size_t stack_len, size_t pos)
{
	if (pos <= stack_len << 1)
		return ((int)pos);
	return ((int)(pos - stack_len));
}

/*
void	ft_insert_cheapest(t_stacks *stacks)
{
	size_t			pos;
	size_t			inst;
	size_t			least_inst;
	t_stack_node	*iter;

	pos = 0;
	iter = stacks->b->head;
	least_inst = (size_t)-1;
	while (pos < stacks->b->len)
	{
		inst = ft_find_insert_pos(stacks->a, iter);
	}
}
*/
