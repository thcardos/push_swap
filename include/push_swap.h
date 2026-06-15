/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:04:25 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:34:22 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
    int				val;
    int				rank;
    int				cost_a;
    int				cost_b;
    struct s_node	*target;
    struct s_node	*next;
}	t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}	t_stack;

/* main.c */
int		main(int argc, char **argv);

/* errors.c */
void	error_exit(t_stack *a, t_stack *b);
void	free_stack(t_stack *s);

/* stack_init.c */
t_stack	*stack_new(void);
t_node	*node_new(int val);
void	stack_push(t_stack *s, int val);

/* parsing.c */
t_stack	*parse_args(int argc, char **argv);
int		ft_atol_check(const char *str, long *out);

/* stack_ops_a.c */
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);

/* stack_ops_b.c */
void	sb(t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);

/* stack_ops_both.c */
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* stack_ops_helpers.c */
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

/* sort_small.c */
void	sort_small(t_stack *a, t_stack *b);

/* sort_big.c */
void	sort_big(t_stack *a, t_stack *b);

/* utils.c */
int		is_sorted(t_stack *a);
int		find_min_pos(t_stack *a);
int		find_max_pos(t_stack *a);
int		find_target_pos(t_stack *a, int val);

/* utils_cost.c */
int		get_cost(t_stack *a, t_stack *b, t_node *node);
void	do_cheapest(t_stack *a, t_stack *b);

/* utils_cost_exec.c */
void	exec_costs(t_stack *a, t_stack *b, int cost_a, int cost_b);

#endif
