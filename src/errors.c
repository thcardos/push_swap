/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:13 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 17:24:14 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
    t_node	*current;
    t_node	*next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void	error_exit(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}