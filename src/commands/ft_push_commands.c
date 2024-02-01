/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:09:16 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 16:14:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_stacks_pa(t_stacks *stacks)
{
	if (!stacks->a || !stacks->b || !stacks->b->len)
		return ;
	ft_stackadd_front(stacks->a, stacks->b->head->value);
	ft_stackdel_front(stacks->b);
	ft_printf("pa\n");
}

void	ft_stacks_pb(t_stacks *stacks)
{
	if (!stacks->a || !stacks->b || !stacks->a->len)
		return ;
	ft_stackadd_front(stacks->b, stacks->a->head->value);
	ft_stackdel_front(stacks->a);
	ft_printf("pb\n");
}
