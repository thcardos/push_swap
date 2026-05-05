/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:26:36 by thcardos          #+#    #+#             */
/*   Updated: 2025/12/09 18:20:41 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_new;
	size_t	start;
	size_t	finish;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	finish = ft_strlen(s1);
	while (finish > start && ft_strchr(set, s1[finish - 1]))
		finish--;
	size = finish - start;
	str_new = malloc(size + 1);
	if (!str_new)
		return (NULL);
	ft_strlcpy(str_new, &s1[start], size + 1);
	return (str_new);
}
