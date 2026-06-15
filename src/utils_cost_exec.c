/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:33:39 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:33:51 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rr_moves(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

static void	exec_rrr_moves(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void	exec_a_moves(t_stack *a, int cost_a)
{
    while (cost_a > 0)
    {
        ra(a);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(a);
        cost_a++;
    }
}

static void	exec_b_moves(t_stack *b, int cost_b)
{
    while (cost_b > 0)
    {
        rb(b);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(b);
        cost_b++;
    }
}

void	exec_costs(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
    exec_rr_moves(a, b, &cost_a, &cost_b);
    exec_rrr_moves(a, b, &cost_a, &cost_b);
    exec_a_moves(a, cost_a);
    exec_b_moves(b, cost_b);
    pa(a, b);
}
