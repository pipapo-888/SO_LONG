/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:04:11 by knomura           #+#    #+#             */
/*   Updated: 2025/05/16 16:18:02 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		i = 0;
		while (i < len && big[i] == little[i] && big[i] && little[i])
			i++;
		if (little[i] == '\0')
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *big = "Hello orld";
//     const char *little = " o";
//     size_t len = 11;

//     char *result = ft_strnstr(big, little, len);

//     if (result != NULL)
//         printf("Found: %s\n", result);
//     else
//         printf("Not Found\n");

//     // char *real_result = strnstr(big, little, len);
//     // printf("Real Found: %s\n", real_result);

//     return 0;
// }
