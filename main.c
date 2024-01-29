/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:39:58 by efret             #+#    #+#             */
/*   Updated: 2024/01/29 18:29:46 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/incl/libft.h"
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

int	ft_check_sorted(t_stack *a, t_stack *b)
{
	t_stack_node	*iter;

	if (!a || !b || (!a->len && !b->len)) // maybe change check for both being empty, we shouldn't be in this funcion if there is no input. Or change the exit status.
		return (-1);
	if (b->len)
		return (0);
	iter = a->head;
	while (iter->next != a->head)
	{
		if (iter->value > iter->next->value)
			return (0);
		iter = iter->next;
	}
	return (1);
}

void	ft_stacks_interactive(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || (!ft_strncmp(line, "q\n", 2) && ft_strlen(line) == 2))
		{
			if (line)
				return (free(line));
			return ;
		}
		if (!ft_strncmp(line, "sa\n", 3) && ft_strlen(line) == 3)
			ft_stacks_sa(a, b);
		else if (!ft_strncmp(line, "sb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_sb(a, b);
		else if (!ft_strncmp(line, "ss\n", 3) && ft_strlen(line) == 3)
			ft_stacks_ss(a, b);
		else if (!ft_strncmp(line, "ra\n", 3) && ft_strlen(line) == 3)
			ft_stacks_ra(a, b);
		else if (!ft_strncmp(line, "rb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_rb(a, b);
		else if (!ft_strncmp(line, "rr\n", 3) && ft_strlen(line) == 3)
			ft_stacks_rr(a, b);
		else if (!ft_strncmp(line, "rra\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rra(a, b);
		else if (!ft_strncmp(line, "rrb\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rrb(a, b);
		else if (!ft_strncmp(line, "rrr\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rrr(a, b);
		else if (!ft_strncmp(line, "pa\n", 3) && ft_strlen(line) == 3)
			ft_stacks_pa(a, b);
		else if (!ft_strncmp(line, "pb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_pb(a, b);
		free(line);
		ft_display_stacks(a, b);
		if (ft_check_sorted(a, b))
		{
			ft_printf("Good job sorting!\n");
			return ;
		}
	}
}

int	main(void)
{
	t_stack *a = ft_calloc(1, sizeof(t_stack));
	//ft_stackadd_front(a, 3);
	//ft_stackadd_front(a, 4);
	//ft_stackadd_front(a, 1);
	//ft_stackadd_front(a, 2);
	ft_stackadd_back(a, 5);
	ft_stackadd_back(a, 1);
	ft_stackadd_back(a, 3);
	ft_stackadd_back(a, 4);
	ft_stackadd_back(a, 2);
	ft_stack_print(a);

	t_stack *b = ft_calloc(1, sizeof(t_stack));
	ft_stack_print(b);

	ft_display_stacks(a, b);

	if (ft_check_sorted(a, b))
		ft_printf("Good job sorting!\nWait a minute... The input was already sorted!\n");
	else
		ft_stacks_interactive(a, b);

	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}

/*
		min-max		actions
123:	0-2
132:	0-1			sa-ra || rra-sa
213:	1-2			sa
231:	2-1			rra
312:	1-0			ra
321:	2-0			ra-sa || sa-rra
*/
