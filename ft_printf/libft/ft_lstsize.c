/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:47:31 by thcardos          #+#    #+#             */
/*   Updated: 2026/01/16 18:03:44 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nodes_count;

	nodes_count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		nodes_count++;
		lst = lst->next;
	}
	return (nodes_count);
}
