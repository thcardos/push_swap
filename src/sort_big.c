/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:52:00 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:39:09 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b_until_three(t_stack *a, t_stack *b)
{
    while (a->size > 3)
        pb(a, b);
}

static void	push_back_all(t_stack *a, t_stack *b)
{
    while (b->size > 0)
        do_cheapest(a, b);
}

static void	rotate_min_to_top(t_stack *a)
{
    int	pos;

    pos = find_min_pos(a);
    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < a->size)
            rra(a);
}

void	sort_big(t_stack *a, t_stack *b)
{
    if (!a || !b || is_sorted(a))
        return ;
    if (a->size <= 5)
    {
        sort_small(a, b);
        return ;
    }
    push_to_b_until_three(a, b);
    sort_small(a, b);
    push_back_all(a, b);
    rotate_min_to_top(a);
}
