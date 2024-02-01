/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:36:33 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 12:57:52 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

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
	stack->last = tmp;
	tmp->next = stack->head;
	(stack->len)++;
}
