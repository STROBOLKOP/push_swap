/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/12 12:49:34 by efret            ###   ########.fr       */
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

size_t	ft_rot_inst_to_cost(int instruction)
{
	if (instruction < 0)
		return ((size_t)(-instruction));
	return ((size_t)instruction);
}

long	ft_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_insert_cost_to_a(t_stacks *stacks, size_t insert_pos, size_t pos_b)
{
	size_t	tmp;
	size_t	cost;

	cost = ft_max(insert_pos, pos_b);
	tmp = ft_max(stacks->a->len - insert_pos, stacks->b->len - pos_b);
	if (tmp < cost)
		cost = tmp;
	tmp = ft_max(stacks->a->len - insert_pos, pos_b);
	if (tmp < cost)
		cost = tmp;
	tmp = ft_max(insert_pos, stacks->b->len - pos_b);
	if (tmp < cost)
		cost = tmp;
	return (cost);
}

int	ft_consider_push_to_b(size_t rank, t_stacks *stacks)
{
	int		groups;
	float	perc;
	int		group_nu;
	size_t	group_size;

	groups = 2;
	perc = (float)curr / (float)max;
	group_nu = perc * (float)groups + 1;
	group_size = max / (size_t)groups;
	return (group_size * group_nu);
}

void	ft_cheapest_to_a(t_stacks *stacks)
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
		cost = ft_insert_cost_to_a(stacks, insert_pos, pos);
		//cost = ft_rot_inst_to_cost(ft_rot_instr(stacks->a->len, insert_pos))
			//+ ft_rot_inst_to_cost(ft_rot_instr(stacks->b->len, pos));
		if (cost < cheapest.cost)
		{
			cheapest.a_rot_inst = ft_rot_instr(stacks->a->len, insert_pos);
			cheapest.b_rot_inst = ft_rot_instr(stacks->b->len, pos);
			cheapest.cost = cost;
		}
		pos++;
		iter = iter->next;
	}
	ft_exec_rotations(stacks, &cheapest);
	//ft_exec_rot_a(stacks->a, cheapest.a_rot_inst);
	//ft_exec_rot_b(stacks->b, cheapest.b_rot_inst);
	(ft_stacks_pa(stacks), ft_printf("pa\n"));
}

void	ft_cheapest_to_b(t_stacks *stacks)
{
	t_data_cheapest	cheapest;
	size_t			pos;
	size_t			cost;
	t_stack_node	*iter;

	pos = 0;
	iter = stacks->a->head;
	cheapest.cost = (size_t)-1;
	cheapest.b_rot_inst = 0;
	while (pos < stacks->a->len)
	{
		if (ft_consider_push_to_b(iter->rank, stacks))
		{
			cost = ft_rot_inst_to_cost(ft_rot_instr(stacks->a->len, pos));
			if (cost < cheapest.cost)
			{
				cheapest.a_rot_inst = ft_rot_instr(stacks->a->len, pos);
				cheapest.cost = cost;
			}
		}
		pos++;
		iter = iter->next;
	}
	ft_exec_rotations(stacks, &cheapest);
	//ft_exec_rot_a(stacks->a, cheapest.a_rot_inst);
	//ft_exec_rot_b(stacks->b, cheapest.b_rot_inst);
	(ft_stacks_pb(stacks), ft_printf("pb\n"));
}
