/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:07:57 by knomura           #+#    #+#             */
/*   Updated: 2025/05/16 16:16:23 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (destsize <= dest_len)
		return (src_len + destsize);
	while (src[i] && dest_len + i < destsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
// int main ()
// {
// 	char dest[10] = "Hello";
// 	char src[] = "World!";
// 	size_t destsize = sizeof(dest); 

// 	size_t ppp = (dest, src, destsize);

// 	printf("%s%zu", dest, ppp);

// 	return (0);
// }
