/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:27:01 by knomura           #+#    #+#             */
/*   Updated: 2025/05/23 00:59:31 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*unsigned_dest;
	const unsigned char	*unsigned_src;

	if (!dest && !src)
		return (NULL);
	unsigned_dest = (unsigned char *)dest;
	unsigned_src = (unsigned char *)src;
	if (unsigned_dest < unsigned_src)
	{
		while (n--)
			*unsigned_dest++ = *unsigned_src++;
	}
	else
	{
		unsigned_dest += n;
		unsigned_src += n;
		while (n--)
			*(--unsigned_dest) = *(--unsigned_src);
	}
	return (dest);
}
// int main ()
// {
// 	char str[] = "12345";
// 	ft_memmove(str , str + 1, 4);
// 	printf("%s\n",str);

// 	// char str2[] = "12345";
// 	// memmove(str2 + 2, str2, 3);
// 	// printf("%s",str2);

// 	return (0);
// }
