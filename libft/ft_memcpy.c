/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:27:41 by knomura           #+#    #+#             */
/*   Updated: 2025/05/12 19:05:04 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*unsigned_dest;
	const unsigned char	*unsigned_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	unsigned_dest = (unsigned char *)dest;
	unsigned_src = (unsigned char *)src;
	while (n--)
		*unsigned_dest++ = *unsigned_src++;
	return (dest);
}
