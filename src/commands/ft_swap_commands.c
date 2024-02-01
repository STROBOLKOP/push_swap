/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:04:58 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 16:17:05 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_sa(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->a || stacks->a->len <= 1)
		return ;
	tmp = stacks->a->head->value;
	stacks->a->head->value = stacks->a->head->next->value;
	stacks->a->head->next->value = tmp;
	ft_printf("sa\n");
}

void	ft_stacks_sb(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->b || stacks->b->len <= 1)
		return ;
	tmp = stacks->b->head->value;
	stacks->b->head->value = stacks->b->head->next->value;
	stacks->b->head->next->value = tmp;
	ft_printf("sb\n");
}

void	ft_stacks_ss(t_stacks *stacks)
{
	ft_stacks_sa(stacks);
	ft_stacks_sb(stacks);
}
