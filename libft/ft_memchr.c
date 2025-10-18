/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:29:54 by knomura           #+#    #+#             */
/*   Updated: 2025/05/12 19:02:45 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	unsigned_char;

	ptr = (unsigned char *)s;
	unsigned_char = (unsigned char)c;
	while (n--)
	{
		if (*ptr == unsigned_char)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
