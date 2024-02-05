/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:04:12 by efret             #+#    #+#             */
/*   Updated: 2024/02/05 17:17:12 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_stack_node	**ft_init_rank_array(t_stack *stack)
{
	t_stack_node	**res;
	t_stack_node	*stack_iter;
	size_t			i;

	res = ft_calloc(stack->len + 1, sizeof(t_stack_node *));
	if (!res)
		return (NULL);
	stack_iter = stack->head;
	i = 0;
	while (i < stack->len)
	{
		res[i++] = stack_iter;
		stack_iter = stack_iter->next;
	}
	return (res);
}

static void	ft_swap_rank_elem(t_stack_node **elem1, t_stack_node **elem2)
{
	t_stack_node	*tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

static void	ft_sort_rank_arr(t_stack_node **rank_arr)
{
	size_t	start_idx;
	size_t	swap_idx;

	start_idx = 1;
	while (rank_arr[start_idx])
	{
		swap_idx = start_idx;
		while (swap_idx > 0)
		{
			if (rank_arr[swap_idx]->value < rank_arr[swap_idx - 1]->value)
				ft_swap_rank_elem(&rank_arr[swap_idx], &rank_arr[swap_idx - 1]);
			else
				break ;
			swap_idx--;
		}
		start_idx++;
	}
}

static int	ft_apply_rank(t_stack_node **rank_arr)
{
	size_t	i;

	i = 0;
	while (rank_arr[i])
	{
		if (!rank_arr)
			return (E_UNEXPECTED_ERROR);
		rank_arr[i]->rank = i;
		i++;
	}
	return (E_SUCCES);
}

int	ft_rank_stack(t_stack *stack)
{
	t_stack_node	**rank_arr;

	rank_arr = ft_init_rank_array(stack);
	if (!rank_arr)
		return (E_MALLOC_FAILURE);
	ft_sort_rank_arr(rank_arr);
	if (ft_apply_rank(rank_arr))
		return (E_UNEXPECTED_ERROR);
	free(rank_arr);
	return (E_SUCCES);
}
