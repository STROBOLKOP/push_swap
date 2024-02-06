/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:36:33 by elias             #+#    #+#             */
/*   Updated: 2024/02/06 11:32:25 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*ft_new_stack_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
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
	stack->head->prev = stack->last;
	stack->last->next = stack->head;
	if (stack->len == 1)
		stack->last->prev = stack->head;
	free(tmp);
	return ; // TODO
}

void	ft_stackdel(t_stack **stack)
{
	if (!*stack)
		return ;
	while ((*stack)->len)
		ft_stackdel_front(*stack);
	free(*stack);
	*stack = NULL;
	return ;
}

void	ft_stackadd_front(t_stack *stack, int value)
{
	t_stack_node	*tmp;

	tmp = ft_new_stack_node(value);
	if (!tmp)
		return (ft_stackdel_front(stack));
	if (!stack->len)
	{
		stack->head = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
		stack->last = tmp;
	}
	if (stack->len)
	{
		stack->head->prev = tmp;
		tmp->next = stack->head;
		tmp->prev = stack->last;
		stack->head = tmp;
		stack->last->next = tmp;
	}
	(stack->len)++;
}

void	ft_stackadd_back(t_stack *stack, int value)
{
	t_stack_node	*tmp;

	tmp = ft_new_stack_node(value);
	if (!tmp)
		return (ft_stackdel_front(stack));
	if (!stack->len)
		stack->head = tmp;
	else
		stack->last->next = tmp;
	tmp->prev = stack->last;
	stack->last = tmp;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	(stack->len)++;
}
