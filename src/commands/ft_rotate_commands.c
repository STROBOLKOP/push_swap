/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:33 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 13:06:45 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_ra(t_stack *a, t_stack *b)
{
	(void)b;
	if (!a || a->len <= 1)
		return ;
	a->last = a->head;
	a->head = a->head->next;
	ft_printf("ra\n");
}

void	ft_stacks_rb(t_stack *a, t_stack *b)
{
	(void)a;
	if (!b || b->len <= 1)
		return ;
	b->last = b->head;
	b->head = b->head->next;
	ft_printf("rb\n");
}

void	ft_stacks_rr(t_stack *a, t_stack *b)
{
	ft_stacks_ra(a, b);
	ft_stacks_rb(a, b);
}
