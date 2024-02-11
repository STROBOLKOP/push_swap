/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:45:20 by elias             #+#    #+#             */
/*   Updated: 2024/02/11 18:33:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_between_incl(int val, int min, int max)
{
	if (min <= val && val <= max)
		return (1);
	return (0);
}

int	ft_is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
		if (!ft_between_incl(*s++, '0', '9'))
			return (0);
	return (1);
}

int	ft_check_sorted(t_stacks *stacks)
{
	t_stack_node	*iter;

	if (!stacks->a || !stacks->b || (!stacks->a->len && !stacks->b->len))
		return (-1);
	if (stacks->b->len)
		return (0);
	iter = stacks->a->head;
	while (iter->next != stacks->a->head)
	{
		if (iter->value > iter->next->value)
			return (0);
		iter = iter->next;
	}
	return (1);
}

void	ft_check_duplicates(t_stacks *stacks)
{
	t_stack_node	*start;
	t_stack_node	*iter;

	if (!stacks)
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
	start = stacks->a->head;
	while (start != stacks->a->last)
	{
		iter = start->next;
		while (iter != stacks->a->head)
		{
			if (start->value == iter->value)
				ft_exit_handler(stacks, E_DUPLICATE_VALUE);
			iter = iter->next;
		}
		start = start->next;
	}
}

void	ft_check_input(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			ft_exit_handler(stacks, E_INVALID_INPUT);
		ft_stackadd_back(stacks->a, ft_atoi_ofc(stacks, argv[i]));
		i++;
	}
	ft_check_duplicates(stacks);
	stacks->count = stacks->a->len;
}
