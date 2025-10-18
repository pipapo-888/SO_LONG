/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:36 by knomura           #+#    #+#             */
/*   Updated: 2025/05/07 18:53:13 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	num = n;
	len = get_num_len(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

// int main ()
// {
// 	int d = 0;

// 	char *num = ft_itoa(d);
// 	printf("%s",num);

// 	return (0);
// }

// int    main(void)
// {
//     int        test_values[] = {0, 42, -42, 2147483647, -2147483648};
//     size_t    i;
//     char    *result;

//     for (i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++)
//     {
//         result = ft_itoa(test_values[i]);
//         if (result)
//         {
//             printf("ft_itoa(%d) = %s\n", test_values[i], result);
//             free(result);
//         }
//         else
//             printf("ft_itoa(%d) = NULL\n", test_values[i]);
//     }
//     return (0);
// }
