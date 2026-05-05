/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:47:05 by thcardos          #+#    #+#             */
/*   Updated: 2025/11/28 17:39:40 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
	}
	return (NULL);
}
