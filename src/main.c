/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:03 by thcardos          #+#    #+#             */
/*   Updated: 2026/05/05 14:14:07 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	*a;

	a = stack_new();
	stack_push(a, 5);
	stack_push(a, 2);
	stack_push(a, 8);
	stack_push(a, 1);
	assign_ranks(a);

	t_node *n = a->top;
	while (n)
	{
		ft_printf("val: %d  rank: %d\n", n->val, n->rank);
		n = n->next;
	}
	free_stack(a);
	return (0);
}
