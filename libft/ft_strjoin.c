/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:57:57 by thcardos          #+#    #+#             */
/*   Updated: 2025/12/05 16:48:01 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	both_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	both_len = (ft_strlen(s1) + ft_strlen(s2));
	s3 = malloc(both_len + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[0 + i];
		i++;
	}
	while ((i - ft_strlen(s1)) < ft_strlen(s2))
	{
		s3[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}
