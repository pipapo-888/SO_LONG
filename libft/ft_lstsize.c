/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:13:17 by knomura           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:42 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list *head = NULL;
// 	int a = 422, b = 232, c = 3, d = 89;

// 	ft_lstadd_front(&head, ft_lstnew(&a)); // [1]
// 	ft_lstadd_front(&head, ft_lstnew(&b)); // [2] -> [1]
// 	ft_lstadd_front(&head, ft_lstnew(&c)); // [3] -> [2] -> [1]
// 	ft_lstadd_front(&head, ft_lstnew(&d)); // [4] -> [3] -> [2] -> [1]

// 	printf("List size: %d\n", ft_lstsize(head)); // → 2

// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("Node content: %d\n", *(int *)(current->content));
// 		current = current->next;
// 	}

// 	return (0);
// }
