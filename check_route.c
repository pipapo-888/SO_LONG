/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:57:18 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 16:35:49 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'Z')
		return ;
	map[y][x] = 'Z';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

void	find_player_and_fill(t_map *map, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while ((size_t)i < map->height)
	{
		j = 0;
		while ((size_t)j < map->width)
		{
			if (map->map[i][j] == 'P')
				flood_fill(map_copy, i, j);
			j++;
		}
		i++;
	}
}

void	check_route(t_map *map, char **map_copy)
{
	int	i;
	int	j;

	find_player_and_fill(map, map_copy);
	i = 0;
	while ((size_t)i < map->height)
	{
		j = 0;
		while ((size_t)j < map->width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map_copy(map_copy, map->height);
				put_error_free_close(0, NULL, "NO PATH", map);
			}
			j++;
		}
		i++;
	}
	free_map_copy(map_copy, map->height);
}
