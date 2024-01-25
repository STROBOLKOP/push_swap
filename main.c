/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:39:58 by efret             #+#    #+#             */
/*   Updated: 2024/01/25 17:47:52 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_new_stack_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_stackdel_front(t_stack *stack)
{
	t_stack_node	*tmp;

	if (!stack || !stack->head)
		return ;
	tmp = stack->head;
	if ((stack->len)-- == 1)
	{
		free(tmp);
		stack->head = NULL;
		stack->last = NULL;
		return ;
	}
	stack->head = tmp->next;
	stack->last->next = stack->head;
	free(tmp);
	return ; // TODO
}

void	ft_stackdel(t_stack **stack)
{
	if (!stack || !(*stack)->head)
		return ;
	while ((*stack)->len)
		ft_stackdel_front(*stack);
	free(*stack);
	*stack = NULL;
	return ;
}

void	ft_stackadd_front(t_stack *stack, int	value)
{
	t_stack_node	*tmp;

	tmp = ft_new_stack_node(value);
	if (!tmp)
		return (ft_stackdel_front(stack));
	if (stack->len == 0)
	{
		stack->head = tmp;
		tmp->next = tmp;
		stack->last = tmp;
	}
	if (stack->len)
	{
		tmp->next = stack->head;
		stack->head = tmp;
	}
	stack->last->next = stack->head;
	(stack->len)++;
}

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

void	ft_display_stacks(t_stack *a, t_stack *b)
{
	size_t			size_diff;
	t_stack_node	*iter_a;
	t_stack_node	*iter_b;
	size_t			min_size;

	ft_printf("----------\n");
	iter_a = a->head;
	iter_b = b->head;
	if (a->len > b->len)
	{
		size_diff = a->len - b->len;
		min_size = b->len;
		while (size_diff--)
		{
			ft_printf(" %d\n", iter_a->value);
			iter_a = iter_a->next;
		}
	}
	else
	{
		size_diff = b->len - a->len;
		min_size = a->len;
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

int	main(void)
{
	t_stack *a = ft_calloc(1, sizeof(t_stack));
	ft_stackadd_front(a, 1);
	ft_stackadd_front(a, 2);
	ft_stackadd_front(a, 4);
	ft_stackadd_front(a, 10);
	ft_stack_print(a);

	t_stack *b = ft_calloc(1, sizeof(t_stack));
	ft_stackadd_front(b, 3);
	ft_stackadd_front(b, 5);
	ft_stack_print(b);
	ft_display_stacks(a, b);

	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}
