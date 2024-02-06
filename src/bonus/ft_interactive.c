/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:57:09 by elias             #+#    #+#             */
/*   Updated: 2024/02/06 17:22:36 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
			(free(line), ft_exit_handler(stacks, E_INVALID_INPUT));
		free(line);
		if (DEBUG)
			(ft_display_stacks(stacks), ft_print_insert_pos(stacks));
		count++;
	}
	return (count);
}
