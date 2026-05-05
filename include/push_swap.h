/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:04:25 by thcardos          #+#    #+#             */
/*   Updated: 2026/05/05 14:16:23 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/* ─── Estructuras ─── */

typedef struct s_node
{
	int				val;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* ─── parsing.c ─── */
t_stack	*parse_args(int argc, char **argv);
int		ft_atol_check(const char *str, long *out);

/* ─── errors.c ─── */
void	error_exit(t_stack *a, t_stack *b);
void	free_stack(t_stack *s);

/* ─── stack_init.c ─── */
t_stack	*stack_new(void);
void	stack_push(t_stack *s, int val);
void	assign_ranks(t_stack *a);

/* ─── stack_ops_a.c ─── */
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);

/* ─── stack_ops_b.c ─── */
void	sb(t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);

/* ─── stack_ops_both.c ─── */
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* ─── sort_small.c ─── */
void	sort_small(t_stack *a, t_stack *b);

/* ─── sort_big.c ─── */
void	sort_big(t_stack *a, t_stack *b);

/* ─── utils.c ─── */
int		is_sorted(t_stack *a);
int		get_max_bits(t_stack *a);

#endif
