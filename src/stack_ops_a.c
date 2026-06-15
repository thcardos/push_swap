/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:51:24 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 17:53:22 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
    t_node	*first;
    t_node	*second;

    if (!a || a->size < 2)
        return ;
    first = a->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    write(1, "sa\n", 3);
}

void	ra(t_stack *a)
{
    t_node	*first;
    t_node	*last;

    if (!a || a->size < 2)
        return ;
    first = a->top;
    last = a->top;
    while (last->next)
        last = last->next;
    a->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
    t_node	*prev;
    t_node	*last;

    if (!a || a->size < 2)
        return ;
    prev = NULL;
    last = a->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
    write(1, "rra\n", 4);
}
