/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:25:11 by efret             #+#    #+#             */
/*   Updated: 2024/02/06 15:26:07 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/incl/libft.h"
# ifndef DEBUG
#  define DEBUG 0
# endif

/* The node of the circular double linked list. */
typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/* Structure of a single stack. */
typedef struct s_stack
{
	t_stack_node	*head;
	t_stack_node	*last;
	size_t			len;
}	t_stack;

/* Structure holding both a and b stacks. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	size_t	count;
}	t_stacks;

/* Exit codes to use for errors. */
enum e_exit_code {
	E_SUCCES,
	E_ERROR,
	E_MALLOC_FAILURE,
	E_INVALID_INPUT,
	E_UNEXPECTED_ERROR,
	E_DUPLICATE_VALUE
};

/* FILE: src/utils/ft_stack_utils.c */

t_stack_node	*ft_new_stack_node(int value);
void	ft_stackadd_front(t_stack *stack, int value);
void	ft_stackadd_back(t_stack *stack, int value);
void	ft_stackdel_front(t_stack *stack);
void	ft_stackdel(t_stack **stack);

/* FILE: src/utils/ft_stacks_utils.c */

void	ft_del_all(t_stacks **stacks);
t_stacks	*ft_init_stacks(void);

/* FILE: src/bonus/ft_display_utils.c */

void	ft_stack_print(t_stack *stack);
void	ft_display_stacks(t_stacks *stacks);
size_t	ft_stacks_interactive(t_stacks *stacks);

/* FILE: src/utils/ft_atoi_ofc.c */

int	ft_atoi_ofc(t_stacks *stacks, const char *nptr);

/* FILE: src/utils/ft_checks.c */

int	ft_is_number(const char *s);
int	ft_check_sorted(t_stacks *stacks);
void	ft_check_duplicates(t_stacks *stacks);
void	ft_check_input(t_stacks *stacks, int argc, char **argv);

/* FILE: src/utils/ft_exit_handler.c */

void	ft_exit_handler(t_stacks *stacks, int exit_code);

/* FILE: src/commands/ft_swap_commands.c */

int	ft_stack_swap(t_stack *stack);
void	ft_stacks_sa(t_stacks *stacks);
void	ft_stacks_sb(t_stacks *stacks);
void	ft_stacks_ss(t_stacks *stacks);

/* FILE: src/commands/ft_rotate_commands.c */

int	ft_stack_rot(t_stack *stack);
void	ft_stacks_ra(t_stacks *stacks);
void	ft_stacks_rb(t_stacks *stacks);
void	ft_stacks_rr(t_stacks *stacks);

/* FILE: src/commands/ft_rev_rotate_commands.c */

int	ft_stack_rev_rot(t_stack *stack);
void	ft_stacks_rra(t_stacks *stacks);
void	ft_stacks_rrb(t_stacks *stacks);
void	ft_stacks_rrr(t_stacks *stacks);

/* FILE: src/commands/ft_push_commands.c */

void	ft_stacks_pa(t_stacks *stacks);
void	ft_stacks_pb(t_stacks *stacks);

/* FILE: src/algorithm/ft_rank_utils.c */

int	ft_rank_stack(t_stack *stack);

/* FILE: src/algorithm/ft_algorithm_utils.c */

size_t	ft_smallest_pos(t_stack *stack);
void	ft_rot_smallest_top(t_stack *stack);
int	ft_check_ordered(t_stack *stack);

/* FILE: src/algorithm/ft_algorithm_solve.c */

void	ft_solve3(t_stacks *stacks);
void	ft_simplest_solve(t_stacks *stacks);
#endif
