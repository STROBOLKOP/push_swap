/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:39:58 by efret             #+#    #+#             */
/*   Updated: 2024/02/15 11:47:26 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (E_SUCCES);
	stacks = ft_init_stacks();
	if (!stacks || !stacks->a || !stacks->b)
		ft_exit_handler(stacks, E_MALLOC_FAILURE);
	ft_check_input(stacks, argc - 1, &argv[1]);
	if (ft_rank_stack(stacks->a))
		ft_exit_handler(stacks, E_UNEXPECTED_ERROR);
	ft_solve(stacks);
	ft_del_all(&stacks);
	return (E_SUCCES);
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
