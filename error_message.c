/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:17:09 by knomura           #+#    #+#             */
/*   Updated: 2025/10/18 19:11:39 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	put_error_free_close(int close_fd, char *line, char *message,
		t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map)
	{
		while ((size_t)i < map->height && map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	get_next_line(-1);
	ft_putstr_fd("Error\n", 2);
	if (line)
		free(line);
	if (close_fd > 0)
		close(close_fd);
	if (message)
		ft_putstr_fd(message, 2);
	exit(1);
}
