/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:52:32 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 17:53:16 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
    t_node	*first;
    t_node	*second;

    if (!b || b->size < 2)
        return ;
    first = b->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
    write(1, "sb\n", 3);
}

void	rb(t_stack *b)
{
    t_node	*first;
    t_node	*last;

    if (!b || b->size < 2)
        return ;
    first = b->top;
    last = b->top;
    while (last->next)
        last = last->next;
    b->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
    t_node	*prev;
    t_node	*last;

    if (!b || b->size < 2)
        return ;
    prev = NULL;
    last = b->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = b->top;
    b->top = last;
    write(1, "rrb\n", 4);
}
