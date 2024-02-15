/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:08 by efret             #+#    #+#             */
/*   Updated: 2024/02/15 11:46:39 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_rot_instr(size_t stack_len, size_t pos)
{
	if (pos <= stack_len >> 1)
		return ((int)pos);
	return ((int)(pos - stack_len));
}

static size_t	ft_insert_cost_to_a(t_stacks *stacks,
		size_t insert_pos, size_t pos_b)
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

int	ft_group(size_t len, size_t rank, t_stacks *stacks, int dir)
{
	size_t	group_size;
	int		group_nu;

	if (stacks->count < 200)
		group_size = 70;
	else
		group_size = 110;
	if (!dir)
		len = stacks->count - len - 1;
	group_nu = len / group_size;
	if (group_size * group_nu <= rank && rank < group_size * (group_nu + 1))
		return (1);
	return (0);
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
		if (ft_group(stacks->a->len, iter->rank, stacks, 0)
			&& cost < cheapest.cost)
		{
			cheapest.a_rot_inst = ft_rot_instr(stacks->a->len, insert_pos);
			cheapest.b_rot_inst = ft_rot_instr(stacks->b->len, pos);
			cheapest.cost = cost;
		}
		pos++;
		iter = iter->next;
	}
	ft_exec_rotations(stacks, &cheapest);
	(ft_stacks_pa(stacks), ft_printf("pa\n"));
}

void	ft_phase_1_to_b(t_stacks *stacks)
{
	if (ft_group(stacks->b->len, stacks->a->head->rank, stacks, 1))
		(ft_stacks_pb(stacks), ft_printf("pb\n"));
	else
		(ft_stacks_ra(stacks), ft_printf("ra\n"));
}
