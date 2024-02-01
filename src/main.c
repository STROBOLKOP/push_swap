/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:39:58 by efret             #+#    #+#             */
/*   Updated: 2024/02/01 13:09:49 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incl/libft.h"
#include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Give me some arguments.\n"); // delete later.
		return (0);
	}

	t_stacks	*stacks;

	stacks = ft_init_stacks();
	ft_check_input(stacks, argc - 1, &argv[1]);
	ft_display_stacks(stacks);
	if (ft_check_sorted(stacks))
		ft_printf("Good job sorting!\nWait a minute... The input was already sorted!\n");
	else
		ft_stacks_interactive(stacks);
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
