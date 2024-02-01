/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:54:04 by elias             #+#    #+#             */
/*   Updated: 2024/02/01 12:55:55 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incl/libft.h"
#include "../../push_swap.h"

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*ret;

	ret = ft_calloc(1, sizeof(t_stacks));
	ret->a = ft_calloc(1, sizeof(t_stack));
	ret->b = ft_calloc(1, sizeof(t_stack));
	return (ret);
}

void	ft_del_all(t_stacks **stacks)
{
	if (!*stacks)
		return ;
	ft_stackdel(&(*stacks)->a);
	ft_stackdel(&(*stacks)->b);
	free(*stacks);
	*stacks = NULL;
}
