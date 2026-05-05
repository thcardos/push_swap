/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:24:16 by thcardos          #+#    #+#             */
/*   Updated: 2025/11/26 17:28:21 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	i = -1;
	if (a < b)
	{
		while (++i < n)
			a[i] = b[i];
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			a[i] = b[i];
		}
	}
	return (dest);
}
