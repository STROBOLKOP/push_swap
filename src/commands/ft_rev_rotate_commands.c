/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:07:34 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 13:09:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_rra(t_stack *a, t_stack *b)
{
	t_stack_node	*tmp;

	(void)b;
	if (!a || a->len <= 1)
		return ;
	tmp = a->head;
	while (tmp->next != a->last)
		tmp = tmp->next;
	a->head = a->last;
	a->last = tmp;
	ft_printf("rra\n");
}

void	ft_stacks_rrb(t_stack *a, t_stack *b)
{
	t_stack_node	*tmp;

	(void)a;
	if (!b || b->len <= 1)
		return ;
	tmp = b->head;
	while (tmp->next != b->last)
		tmp = tmp->next;
	b->head = b->last;
	b->last = tmp;
	ft_printf("rrb\n");
}

void	ft_stacks_rrr(t_stack *a, t_stack *b)
{
	ft_stacks_rra(a, b);
	ft_stacks_rrb(a, b);
}
