/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:33 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 16:18:22 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_ra(t_stacks *stacks)
{
	if (!stacks->a || stacks->a->len <= 1)
		return ;
	stacks->a->last = stacks->a->head;
	stacks->a->head = stacks->a->head->next;
	ft_printf("ra\n");
}

void	ft_stacks_rb(t_stacks *stacks)
{
	if (!stacks->b || stacks->b->len <= 1)
		return ;
	stacks->b->last = stacks->b->head;
	stacks->b->head = stacks->b->head->next;
	ft_printf("rb\n");
}

void	ft_stacks_rr(t_stacks *stacks)
{
	ft_stacks_ra(stacks);
	ft_stacks_rb(stacks);
}
