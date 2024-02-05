/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:25:11 by efret             #+#    #+#             */
/*   Updated: 2024/02/05 16:51:35 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/incl/libft.h"
# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
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

enum e_exit_code {
	E_SUCCES,
	E_ERROR,
	E_MALLOC_FAILURE,
	E_INVALID_INPUT,
	E_UNEXPECTED_ERROR,
	E_DUPLICATE_VALUE
};

t_stack_node	*ft_new_stack_node(int value);
void	ft_stackadd_front(t_stack *stack, int value);
void	ft_stackadd_back(t_stack *stack, int value);
void	ft_stackdel_front(t_stack *stack);
void	ft_stackdel(t_stack **stack);

void	ft_del_all(t_stacks **stacks);
t_stacks	*ft_init_stacks(void);

void	ft_stack_print(t_stack *stack);
void	ft_display_stacks(t_stacks *stacks);
size_t	ft_stacks_interactive(t_stacks *stacks);

int	ft_atoi_ofc(t_stacks *stacks, const char *nptr);

int	ft_is_number(const char *s);
int	ft_check_sorted(t_stacks *stacks);
void	ft_check_duplicates(t_stacks *stacks);
void	ft_check_input(t_stacks *stacks, int argc, char **argv);

void	ft_exit_handler(t_stacks *stacks, int exit_code);

int	ft_stack_swap(t_stack *stack);
void	ft_stacks_sa(t_stacks *stacks);
void	ft_stacks_sb(t_stacks *stacks);
void	ft_stacks_ss(t_stacks *stacks);

int	ft_stack_rot(t_stack *stack);
void	ft_stacks_ra(t_stacks *stacks);
void	ft_stacks_rb(t_stacks *stacks);
void	ft_stacks_rr(t_stacks *stacks);

int	ft_stack_rev_rot(t_stack *stack);
void	ft_stacks_rra(t_stacks *stacks);
void	ft_stacks_rrb(t_stacks *stacks);
void	ft_stacks_rrr(t_stacks *stacks);

void	ft_stacks_pa(t_stacks *stacks);
void	ft_stacks_pb(t_stacks *stacks);

int	ft_rank_stack(t_stack *stack);

void	ft_rot_smallest_top(t_stack *stack);
void	ft_simplest_solve(t_stacks *stacks);
#endif
