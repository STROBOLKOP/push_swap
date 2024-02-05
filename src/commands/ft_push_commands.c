/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:09:16 by elias             #+#    #+#             */
/*   Updated: 2024/02/05 15:46:15 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

int	ft_stack_push(t_stack *dest, t_stack *src)
{
	if (!dest || !src)
		return (E_UNEXPECTED_ERROR);
	if (!src->len)
		return (E_SUCCES);
	ft_stackadd_front(dest, src->head->value);
	ft_stackdel_front(src);
	return (E_SUCCES);
}

void	ft_stacks_pa(t_stacks *stacks)
{
	ft_stack_push(stacks->a, stacks->b);
	ft_printf("pa\n");
}

void	ft_stacks_pb(t_stacks *stacks)
{
	ft_stack_push(stacks->b, stacks->a);
	ft_printf("pb\n");
}
