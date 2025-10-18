/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:28:51 by knomura           #+#    #+#             */
/*   Updated: 2025/05/07 18:55:37 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed = malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}
// int	main()
// {
// 	char str[] = "Hello world";
// 	char set[] = "Hew ";
// 	char *check = ft_strtrim(str, set);
// 	char *check2 = "NULL";
// 	char check3 = '\0';
//     printf("%s\n", check);
//     printf("%s\n", check2);
// 	printf("%c\n", check3);
// 	printf("\n");

// 	return (0);
// }
