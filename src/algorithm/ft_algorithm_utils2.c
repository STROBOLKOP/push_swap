/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/06 18:44:32 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	ft_find_insert_pos(t_stack *stack, t_stack_node *node)
{
	size_t			pos;
	t_stack_node	*iter;

	if (!stack->len)
		return (0);
	pos = 0;
	iter = stack->head;
	while (iter->rank < node->rank && pos < stack->len)
	{
		//ft_printf("pos: %d\trank a: %d\trank node: %d\n", pos, iter->rank, node->rank);
		iter = iter->next;
		pos++;
	}
	return (pos);
}
