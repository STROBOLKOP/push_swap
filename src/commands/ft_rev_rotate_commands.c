/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:07:34 by elias             #+#    #+#             */
/*   Updated: 2024/02/15 12:10:36 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_stack_rev_rot(t_stack *stack)
{
	if (!stack)
		return (E_UNEXPECTED_ERROR);
	if (stack->len <= 1)
		return (E_SUCCES);
	stack->head = stack->head->prev;
	stack->last = stack->last->prev;
	return (E_SUCCES);
}

void	ft_stacks_rra(t_stacks *stacks)
{
	if (ft_stack_rev_rot(stacks->a))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
}

void	ft_stacks_rrb(t_stacks *stacks)
{
	if (ft_stack_rev_rot(stacks->b))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
}

void	ft_stacks_rrr(t_stacks *stacks)
{
	ft_stacks_rra(stacks);
	ft_stacks_rrb(stacks);
}
