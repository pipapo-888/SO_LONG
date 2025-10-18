/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:03:22 by knomura           #+#    #+#             */
/*   Updated: 2025/05/07 18:59:23 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void to_upper_if_even(unsigned int i, char *c)
// {
//     if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
//         *c -= 32;
// }

// int main()
// {
//     char str[] = "hello world";
//     ft_striteri(str, to_upper_if_even);
//     printf("%s", str);

//     return (0);
// }
