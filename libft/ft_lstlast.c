/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:34:31 by knomura           #+#    #+#             */
/*   Updated: 2025/05/11 14:21:15 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		i++;
		lst = lst -> next;
	}
	return (lst);
}
// t_list	*ft_lstlast(t_list *lst)
// {
// 	int	len;
// 	int	i;

// 	i = 0;
// 	len = ft_lstsize(lst);

// 	while (i < len - 1)
// 	{
// 		i++;
// 		lst = lst -> next;
// 	}
// 	return (lst);
// }
