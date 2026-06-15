/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:30 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 17:15:39 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

t_stack	*stack_new(void)
{
    t_stack	*stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

t_node	*node_new(int val)
{
    t_node	*node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->val = val;
    node->rank = 0;
    node->cost_a = 0;
    node->cost_b = 0;
    node->target = NULL;
    node->next = NULL;
    return (node);
}

void	stack_push(t_stack *stack, int val)
{
    t_node	*new_node;

    if (!stack)
        return ;
    new_node = node_new(val);
    if (!new_node)
        return ;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}