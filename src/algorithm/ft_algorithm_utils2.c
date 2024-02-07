/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/07 12:14:45 by efret            ###   ########.fr       */
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
