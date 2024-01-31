/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:25:11 by efret             #+#    #+#             */
/*   Updated: 2024/01/31 18:49:41 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/incl/libft.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	t_stack_node	*last;
	size_t			len;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	size_t	count;
}	t_stacks;

enum exit_code {
	E_SUCCES,
	E_ERROR,
	E_INVALID_INPUT,
	E_UNEXPECTED_ERROR
};

#endif
