/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:57:09 by elias             #+#    #+#             */
/*   Updated: 2024/02/03 13:28:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
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

size_t	ft_stacks_interactive(t_stacks *stacks)
{
	char	*line;
	size_t	count;

	count = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (count);
		if (!ft_strncmp(line, "sa\n", 3) && ft_strlen(line) == 3)
			ft_stacks_sa(stacks);
		else if (!ft_strncmp(line, "sb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_sb(stacks);
		else if (!ft_strncmp(line, "ss\n", 3) && ft_strlen(line) == 3)
			ft_stacks_ss(stacks);
		else if (!ft_strncmp(line, "ra\n", 3) && ft_strlen(line) == 3)
			ft_stacks_ra(stacks);
		else if (!ft_strncmp(line, "rb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_rb(stacks);
		else if (!ft_strncmp(line, "rr\n", 3) && ft_strlen(line) == 3)
			ft_stacks_rr(stacks);
		else if (!ft_strncmp(line, "rra\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rra(stacks);
		else if (!ft_strncmp(line, "rrb\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rrb(stacks);
		else if (!ft_strncmp(line, "rrr\n", 4) && ft_strlen(line) == 4)
			ft_stacks_rrr(stacks);
		else if (!ft_strncmp(line, "pa\n", 3) && ft_strlen(line) == 3)
			ft_stacks_pa(stacks);
		else if (!ft_strncmp(line, "pb\n", 3) && ft_strlen(line) == 3)
			ft_stacks_pb(stacks);
		else
		{
			free(line);
			ft_exit_handler(stacks, E_INVALID_INPUT);
		}
		free(line);
		if (DEBUG)
			ft_display_stacks(stacks);
		count++;
	}
	return (count);
}
