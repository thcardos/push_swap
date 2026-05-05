/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:25:35 by thcardos          #+#    #+#             */
/*   Updated: 2026/01/19 15:46:16 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	nbr_word;
	size_t	i;

	if (!s)
		return (0);
	nbr_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nbr_word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nbr_word);
}

static void	free_all(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**fill_array(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (free_all(result, j), NULL);
			j++;
		}
	}
	return (result[j] = NULL, result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_array(result, s, c));
}
