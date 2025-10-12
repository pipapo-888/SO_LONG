/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:17:09 by knomura           #+#    #+#             */
/*   Updated: 2025/10/12 18:25:31 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void put_error_free_close(int fd, char *line, char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (message)
		ft_putstr_fd(message, 2);
	exit(1);
}
