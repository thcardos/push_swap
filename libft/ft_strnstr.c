/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:08:56 by thcardos          #+#    #+#             */
/*   Updated: 2025/11/28 20:39:02 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
