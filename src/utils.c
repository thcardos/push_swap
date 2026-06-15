/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:51:33 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 17:51:34 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
    t_node	*current;

    if (!a || !a->top)
        return (1);
    current = a->top;
    while (current->next)
    {
        if (current->val > current->next->val)
            return (0);
        current = current->next;
    }
    return (1);
}

int	find_min_pos(t_stack *a)
{
    t_node	*current;
    int		min;
    int		pos;
    int		min_pos;

    if (!a || !a->top)
        return (0);
    current = a->top;
    min = current->val;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->val < min)
        {
            min = current->val;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (min_pos);
}

int	find_max_pos(t_stack *a)
{
    t_node	*current;
    int		max;
    int		pos;
    int		max_pos;

    if (!a || !a->top)
        return (0);
    current = a->top;
    max = current->val;
    pos = 0;
    max_pos = 0;
    while (current)
    {
        if (current->val > max)
        {
            max = current->val;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (max_pos);
}

int	find_target_pos(t_stack *a, int val)
{
    t_node	*current;
    int		best;
    int		pos;
    int		best_pos;

    if (!a || !a->top)
        return (0);
    current = a->top;
    best = INT_MAX;
    best_pos = find_min_pos(a);
    pos = 0;
    while (current)
    {
        if (current->val > val && current->val < best)
        {
            best = current->val;
            best_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (best_pos);
}
