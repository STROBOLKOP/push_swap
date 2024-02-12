/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:46 by efret             #+#    #+#             */
/*   Updated: 2024/02/12 16:37:51 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_exec_rot_a(t_stack *stack, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			(ft_stack_rot(stack), ft_printf("ra\n"));
	else
		while (rot_inst++)
			(ft_stack_rev_rot(stack), ft_printf("rra\n"));
}

static void	ft_exec_rot_b(t_stack *stack, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			(ft_stack_rot(stack), ft_printf("rb\n"));
	else
		while (rot_inst++)
			(ft_stack_rev_rot(stack), ft_printf("rrb\n"));
}

static void	ft_exec_simul_rot(t_stacks *stacks, int rot_inst)
{
	if (rot_inst >= 0)
		while (rot_inst--)
			(ft_stacks_rr(stacks), ft_printf("rr\n"));
	else
		while (rot_inst++)
			(ft_stacks_rrr(stacks), ft_printf("rrr\n"));
}

void	ft_exec_rotations(t_stacks *stacks, t_data_cheapest *cheapest)
{
	int	sign_a;
	int	sign_b;

	sign_a = cheapest->a_rot_inst >= 0;
	sign_b = cheapest->b_rot_inst >= 0;
	cheapest->rr_inst = 0;
	if (sign_a == sign_b)
	{
		if ((cheapest->a_rot_inst > cheapest->b_rot_inst && sign_a)
			|| (cheapest->a_rot_inst < cheapest->b_rot_inst && !sign_a))
			cheapest->rr_inst = cheapest->b_rot_inst;
		else if ((cheapest->a_rot_inst < cheapest->b_rot_inst && sign_a)
			|| (cheapest->a_rot_inst > cheapest->b_rot_inst && !sign_a))
			cheapest->rr_inst = cheapest->a_rot_inst;
		cheapest->a_rot_inst -= cheapest->rr_inst;
		cheapest->b_rot_inst -= cheapest->rr_inst ;
	}
	ft_exec_simul_rot(stacks, cheapest->rr_inst);
	ft_exec_rot_a(stacks->a, cheapest->a_rot_inst);
	ft_exec_rot_b(stacks->b, cheapest->b_rot_inst);
}

void	ft_rot_smallest_top(t_stack *stack)
{
	size_t	pos_smallest;
	int		rot_inst;

	pos_smallest = ft_smallest_pos(stack);
	rot_inst = ft_rot_instr(stack->len, pos_smallest);
	ft_exec_rot_a(stack, rot_inst);
}
