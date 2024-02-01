/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:09:16 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 13:09:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->len)
		return ;
	ft_stackadd_front(a, b->head->value);
	ft_stackdel_front(b);
	ft_printf("pa\n");
}

void	ft_stacks_pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->len)
		return ;
	ft_stackadd_front(b, a->head->value);
	ft_stackdel_front(a);
	ft_printf("pb\n");
}
