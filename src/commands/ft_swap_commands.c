/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:04:58 by elias             #+#    #+#             */
/*   Updated: 2024/02/15 12:15:15 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_stack_swap(t_stack *stack)
{
	int		tmp;
	size_t	tmp_rank;

	if (!stack)
		return (E_UNEXPECTED_ERROR);
	if (stack->len <= 1)
		return (E_SUCCES);
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	tmp_rank = stack->head->rank;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->rank = tmp_rank;
	return (E_SUCCES);
}

void	ft_stacks_sa(t_stacks *stacks)
{
	ft_stack_swap(stacks->a);
}

void	ft_stacks_sb(t_stacks *stacks)
{
	ft_stack_swap(stacks->b);
}

void	ft_stacks_ss(t_stacks *stacks)
{
	ft_stacks_sa(stacks);
	ft_stacks_sb(stacks);
}
