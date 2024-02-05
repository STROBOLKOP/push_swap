/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:04:58 by elias             #+#    #+#             */
/*   Updated: 2024/02/05 15:06:17 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

int	ft_stack_swap(t_stack *stack)
{
	int tmp;

	if (!stack || stack->len <= 1)
		return (E_UNEXPECTED_ERROR);
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	return (E_SUCCES);
}

void	ft_stacks_sa(t_stacks *stacks)
{
	ft_stack_swap(stacks->a);
	ft_printf("sa\n");
}

void	ft_stacks_sb(t_stacks *stacks)
{
	ft_stack_swap(stacks->b);
	ft_printf("sb\n");
}

void	ft_stacks_ss(t_stacks *stacks)
{
	ft_stacks_sa(stacks);
	ft_stacks_sb(stacks);
}
