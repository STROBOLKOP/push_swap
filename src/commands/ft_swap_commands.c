/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:04:58 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 13:05:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_sa(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (!a || a->len <= 1)
		return ;
	tmp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = tmp;
	ft_printf("sa\n");
}

void	ft_stacks_sb(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (!b || b->len <= 1)
		return ;
	tmp = b->head->value;
	b->head->value = b->head->next->value;
	b->head->next->value = tmp;
	ft_printf("sb\n");
}

void	ft_stacks_ss(t_stack *a, t_stack *b)
{
	ft_stacks_sa(a, b);
	ft_stacks_sb(a, b);
}
