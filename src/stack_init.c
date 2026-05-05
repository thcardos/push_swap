/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:30 by thcardos          #+#    #+#             */
/*   Updated: 2026/05/05 14:14:31 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	stack_push(t_stack *s, int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->val = val;
	node->rank = 0;
	node->next = s->top;
	s->top = node;
	s->size++;
}

void	assign_ranks(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = a->top;
	while (i)
	{
		rank = 0;
		j = a->top;
		while (j)
		{
			if (j->val < i->val)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}
