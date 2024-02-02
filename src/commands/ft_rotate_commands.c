/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:33 by elias             #+#    #+#             */
/*   Updated: 2024/02/02 16:05:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

int	ft_stack_rot(t_stack *stack)
{
	if (!stack || stack->len <= 1)
		return (E_UNEXPECTED_ERROR);
	stack->last = stack->head;
	stack->head = stack->head->next;
	return (E_SUCCES);
}

void	ft_stacks_ra(t_stacks *stacks)
{
	if (ft_stack_rot(stacks->a))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
	ft_printf("ra\n");
}

void	ft_stacks_rb(t_stacks *stacks)
{
	if (ft_stack_rot(stacks->b))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
	ft_printf("rb\n");
}

void	ft_stacks_rr(t_stacks *stacks)
{
	ft_stacks_ra(stacks);
	ft_stacks_rb(stacks);
}
