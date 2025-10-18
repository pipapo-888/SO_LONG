/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:38:21 by knomura           #+#    #+#             */
/*   Updated: 2025/05/07 14:48:29 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	totalsize = count * size;
	ptr = malloc(totalsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, totalsize);
	return (ptr);
}
