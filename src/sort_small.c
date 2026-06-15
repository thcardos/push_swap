/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:52:03 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:38:49 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack *a)
{
    int	pos;

    if (!a || a->size < 2)
        return ;
    pos = find_min_pos(a);
    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < a->size)
            rra(a);
}

static void	sort_three(t_stack *a)
{
    int	first;
    int	second;
    int	third;

    if (!a || a->size != 3 || is_sorted(a))
        return ;
    first = a->top->val;
    second = a->top->next->val;
    third = a->top->next->next->val;
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

static void	sort_four(t_stack *a, t_stack *b)
{
    move_min_to_top(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
    move_min_to_top(a);
    pb(a, b);
    move_min_to_top(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
    if (!a || !b || is_sorted(a))
        return ;
    if (a->size == 2 && a->top->val > a->top->next->val)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size == 4)
        sort_four(a, b);
    else if (a->size == 5)
        sort_five(a, b);
}
