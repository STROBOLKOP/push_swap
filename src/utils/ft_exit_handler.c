/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:10 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 12:48:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

void	ft_exit_handler(t_stacks *stacks, int exit_code)
{
	ft_del_all(&stacks);
	ft_putendl_fd("Error", 2);
	exit(exit_code);
}
