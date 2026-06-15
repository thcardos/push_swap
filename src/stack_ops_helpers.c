/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:59:40 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 18:09:49 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
    t_node	*first;
    t_node	*last;

    if (!stack || stack->size < 2)
        return ;
    first = stack->top;
    last = stack->top;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
}

void	reverse_rotate_stack(t_stack *stack)
{
    t_node	*prev;
    t_node	*last;

    if (!stack || stack->size < 2)
        return ;
    prev = NULL;
    last = stack->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
}
