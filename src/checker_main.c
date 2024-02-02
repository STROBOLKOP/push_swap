/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:47:03 by elias             #+#    #+#             */
/*   Updated: 2024/02/02 16:52:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	size_t		count;

	if (argc < 2)
		return (0);
	stacks = ft_init_stacks();
	ft_check_input(stacks, argc - 1, &argv[1]);
	//ft_display_stacks(stacks);
	count = ft_stacks_interactive(stacks);
	if (ft_check_sorted(stacks))
		ft_printf("OK: Good job sorting!\n");
	else
		ft_printf("KO: Oh no, that did not sort it :(\n");
	ft_printf("You did %d instrucions.\n", count);
	ft_del_all(&stacks);
	return (0);
}
