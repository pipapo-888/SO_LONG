/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:02:28 by knomura           #+#    #+#             */
/*   Updated: 2025/05/07 18:49:29 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char to_upper(char c)
// {
//     if (c >= 'a' && c <= 'z')
//         return (c - 32);
//     return (c);
// }

// char to_upper_odd(unsigned int i, char c)
// {
//     if (i % 2 == 1 && c >= 'a' && c <= 'z')
//         return (c - 32);
//     return (c);
// }

// int main (void)
// {
//     char *s = "abcdef";
//     char *result = ft_strmapi(s, to_upper_odd);
//     printf("%s", result);
//     free(result);

// }
