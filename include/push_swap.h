/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:04:25 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/16 11:54:12 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				rank;
	int				cost_a;
	int				cost_b;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				error_exit(t_stack *a, t_stack *b);
void				free_stack(t_stack *s);

t_stack				*parse_args(int argc, char **argv);
int					ft_atol_check(const char *str, long *out);

int					main(int argc, char **argv);

void				sort_big(t_stack *a, t_stack *b);

void				sort_small(t_stack *a, t_stack *b);

t_stack				*stack_new(void);
t_node				*node_new(int val);
void				stack_push(t_stack *s, int val);

void				sa(t_stack *a);
void				ra(t_stack *a);
void				rra(t_stack *a);

void				sb(t_stack *b);
void				rb(t_stack *b);
void				rrb(t_stack *b);

void				ss(t_stack *a, t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				rotate_stack(t_stack *stack);
void				reverse_rotate_stack(t_stack *stack);

void				exec_costs(t_stack *a, t_stack *b, int cost_a, int cost_b);

int					get_cost(t_stack *a, t_stack *b, t_node *node);
void				do_cheapest(t_stack *a, t_stack *b);

int					is_sorted(t_stack *a);
int					find_min_pos(t_stack *a);
int					find_max_pos(t_stack *a);
int					find_target_pos(t_stack *a, int val);

#endif
