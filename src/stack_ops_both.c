/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:52:52 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 18:09:38 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
    t_node	*first;
    t_node	*second;
    int		changed;

    changed = 0;
    if (a && a->size >= 2)
    {
        first = a->top;
        second = first->next;
        first->next = second->next;
        second->next = first;
        a->top = second;
        changed = 1;
    }
    if (b && b->size >= 2)
    {
        first = b->top;
        second = first->next;
        first->next = second->next;
        second->next = first;
        b->top = second;
        changed = 1;
    }
    if (changed)
        write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
    if (a && a->size >= 2)
        rotate_stack(a);
    if (b && b->size >= 2)
        rotate_stack(b);
    if ((a && a->size >= 2) || (b && b->size >= 2))
        write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
    if (a && a->size >= 2)
        reverse_rotate_stack(a);
    if (b && b->size >= 2)
        reverse_rotate_stack(b);
    if ((a && a->size >= 2) || (b && b->size >= 2))
        write(1, "rrr\n", 4);
}

void	pa(t_stack *a, t_stack *b)
{
    t_node	*node;

    if (!b || !b->top)
        return ;
    node = b->top;
    b->top = node->next;
    b->size--;
    node->next = a->top;
    a->top = node;
    a->size++;
    write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
    t_node	*node;

    if (!a || !a->top)
        return ;
    node = a->top;
    a->top = node->next;
    a->size--;
    node->next = b->top;
    b->top = node;
    b->size++;
    write(1, "pb\n", 3);
}
