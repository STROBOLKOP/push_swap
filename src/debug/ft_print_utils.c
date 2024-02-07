/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:18:59 by efret             #+#    #+#             */
/*   Updated: 2024/02/07 16:14:00 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_stack_print(t_stack *stack)
{
	t_stack_node	*iter;

	if (!stack)
		return ;
	if (!stack->head)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	iter = stack->head;
	ft_printf("HEAD -> %d", iter->value);
	iter = iter->next;
	while (iter != stack->head)
	{
		ft_printf(" -> %d", iter->value);
		iter = iter->next;
	}
	ft_printf("\n");
}

void	ft_display_stacks(t_stacks *stacks)
{
	size_t			size_diff;
	t_stack_node	*iter_a;
	t_stack_node	*iter_b;
	size_t			min_size;

	ft_printf("----------\n");
	iter_a = stacks->a->head;
	iter_b = stacks->b->head;
	if (stacks->a->len > stacks->b->len)
	{
		size_diff = stacks->a->len - stacks->b->len;
		min_size = stacks->b->len;
		while (size_diff--)
		{
			ft_printf(" %d\n", iter_a->value);
			iter_a = iter_a->next;
		}
	}
	else
	{
		size_diff = stacks->b->len - stacks->a->len;
		min_size = stacks->a->len;
		while (size_diff--)
		{
			ft_printf(" \t%d\n", iter_b->value);
			iter_b = iter_b->next;
		}
	}
	while (min_size--)
	{
		ft_printf(" %d\t%d\n", iter_a->value, iter_b->value);
		iter_a = iter_a->next;
		iter_b = iter_b->next;
	}
	ft_printf(" _\t_\n a\tb\n");
}

void	ft_print_insert_pos(t_stacks *stacks)
{
	t_stack_node	*iter;
	
	iter = stacks->b->head;
	for (size_t i = 0; i < stacks->b->len; i++)
	{
		ft_printf("Where to insert %d in a: %d\n", i, ft_find_insert_pos(stacks->a, iter));
		iter = iter->next;
	}
}
