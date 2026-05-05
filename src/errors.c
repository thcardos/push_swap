/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:13 by thcardos          #+#    #+#             */
/*   Updated: 2026/05/05 14:16:12 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	if (!s)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(s);
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}