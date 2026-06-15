/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:03 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:40:01 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 1)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		error_exit(NULL, NULL);
	b = stack_new();
	if (!b)
		error_exit(a, NULL);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}