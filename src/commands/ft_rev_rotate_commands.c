/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:07:34 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 16:19:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_rra(t_stacks *stacks)
{
	t_stack_node	*tmp;

	if (!stacks->a || stacks->a->len <= 1)
		return ;
	tmp = stacks->a->head;
	while (tmp->next != stacks->a->last)
		tmp = tmp->next;
	stacks->a->head = stacks->a->last;
	stacks->a->last = tmp;
	ft_printf("rra\n");
}

void	ft_stacks_rrb(t_stacks *stacks)
{
	t_stack_node	*tmp;

	if (!stacks->b || stacks->b->len <= 1)
		return ;
	tmp = stacks->b->head;
	while (tmp->next != stacks->b->last)
		tmp = tmp->next;
	stacks->b->head = stacks->b->last;
	stacks->b->last = tmp;
	ft_printf("rrb\n");
}

void	ft_stacks_rrr(t_stacks *stacks)
{
	ft_stacks_rra(stacks);
	ft_stacks_rrb(stacks);
}
