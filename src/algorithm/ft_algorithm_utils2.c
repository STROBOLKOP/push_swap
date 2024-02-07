/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/07 16:41:33 by efret            ###   ########.fr       */
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

int	ft_rot_instr(size_t stack_len, size_t pos)
{
	if (pos <= stack_len >> 1)
		return ((int)pos);
	return ((int)(pos - stack_len));
}

size_t	ft_rot_inst_to_cost(int	instruction)
{
	if (instruction < 0)
		return ((size_t)(-instruction));
	return ((size_t)instruction);
}

void	ft_insert_cheapest(t_stacks *stacks)
{
	t_data_cheapest	cheapest;
	size_t			pos;
	size_t			insert_pos;
	size_t			cost;
	t_stack_node	*iter;

	pos = 0;
	iter = stacks->b->head;
	cheapest.cost = (size_t)-1;
	while (pos < stacks->b->len)
	{
		insert_pos = ft_find_insert_pos(stacks->a, iter);
		cost = ft_rot_inst_to_cost(ft_rot_instr(stacks->a->len, insert_pos))
				+ ft_rot_inst_to_cost(ft_rot_instr(stacks->b->len, pos));
		if (cost < cheapest.cost)
		{
			cheapest.a_rot_inst = ft_rot_instr(stacks->a->len, insert_pos);
			cheapest.b_rot_inst = ft_rot_instr(stacks->b->len, pos);
			cheapest.cost = cost + cheapest.a_rot_inst + cheapest.b_rot_inst;
		}
		pos++;
		iter = iter->next;
	}
	ft_exec_rot_a(stacks->a, cheapest.a_rot_inst);
	ft_exec_rot_b(stacks->b, cheapest.b_rot_inst);
	(ft_stacks_pa(stacks), ft_printf("pa\n"));
}
