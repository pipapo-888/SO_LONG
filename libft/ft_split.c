/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:51:46 by knomura           #+#    #+#             */
/*   Updated: 2025/05/14 18:20:21 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	if (*s == '\0')
		return (0);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **result, int i)
{
	while (--i >= 0)
		free(result[i]);
	free(result);
}

int	split_string(const char *s, char c, char **result, size_t word_count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = 0;
	while (i < word_count)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		result[i] = ft_substr(s, start, end - start);
		if (result[i] == NULL)
		{
			free_split(result, i);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;
	int		null_checker;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	null_checker = split_string(s, c, result, word_count);
	if (null_checker == 0)
		return (NULL);
	result[word_count] = NULL;
	return (result);
}
