/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:39:58 by efret             #+#    #+#             */
/*   Updated: 2024/02/01 18:10:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = ft_init_stacks();
	ft_check_input(stacks, argc - 1, &argv[1]);
	ft_printf("sa\n");
	ft_del_all(&stacks);
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
