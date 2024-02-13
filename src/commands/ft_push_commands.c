/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:09:16 by elias             #+#    #+#             */
/*   Updated: 2024/02/13 12:09:10 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_stack_push(t_stack *dest, t_stack *src)
{
	if (!dest || !src)
		return (E_UNEXPECTED_ERROR);
	if (!src->len)
		return (E_SUCCES);
	if (ft_stackadd_front(dest, src->head->value))
		return (E_MALLOC_FAILURE);
	dest->head->rank = src->head->rank;
	ft_stackdel_front(src);
	return (E_SUCCES);
}

void	ft_stacks_pa(t_stacks *stacks)
{
	if (ft_stack_push(stacks->a, stacks->b))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
}

void	ft_stacks_pb(t_stacks *stacks)
{
	if (ft_stack_push(stacks->b, stacks->a))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
}
