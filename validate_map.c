/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:58:41 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 12:55:04 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void flood_fill(char** map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'Z')
		return;

	map[y][x] = 'Z';

	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

void	check_route(t_map* map)
{
	char** map_copy;
	int i;
	int j;

	map_copy = malloc(sizeof(char*) * (map->height + 1));
	i = 0;

	while ((size_t)i < map->height)
	{
		map_copy[i] = strdup(map->map[i]);
		i++;
	}
	map_copy[i] = NULL;
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
	i = 0;

	printf("\n");
	while (map_copy[i])
	{
		printf("%s\n", map_copy[i]);
		i++;
	}

	i = 0;
	while ((size_t)i < map->height)
	{
		j = 0;
		while ((size_t)j < map->width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				put_error_free_close(0, NULL, "NO PATH");
			j++;
		}
		i++;
	}

	for (i = 0; (size_t)i < map->height; i++)
	{
		free(map_copy[i]);
	}
	free(map_copy);
}

void	check_wall(t_map* map)
{
	int i;

	i = 0;
	while ((size_t)i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			put_error_free_close(0, NULL, "NO WALL\n");
		i++;
	}
	i = 0;
	while ((size_t)i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			put_error_free_close(0, NULL, "NO WALL\n");
		i++;
	}
}


int	allowed(char c, t_map* map, int i, int j)
{
	if (c == '0' || c == '1')
		;
	else if (c == 'P')
		map->player_count++;
	else if (c == 'E')
	{
		map->exit_count++;
		map->exit_x = j;
		map->exit_y = i;
	}
	else if (c == 'C')
		map->coin_count++;
	else
		return (0);
	return (1);
}

void	check_iregular(t_map* map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((size_t)i < map->height)
	{
		j = 0;
		while ((size_t)j < map->width)
		{
			if (!allowed(map->map[i][j], map, i, j))
			{
				free_map(map);
				put_error_free_close(0, NULL, "Unallowed Variable Included\n");
			}
			j++;
		}
		i++;
	}
	if (map->coin_count < 1 || map->player_count != 1 || map->exit_count != 1)
	{
		free_map(map);
		put_error_free_close(0, NULL,
			"1 exit,1 starting position and at least 1 collectible.\n");
	}
}

void	validate_map(t_map* map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	if (map->height > 30 || map->width > 50)
		put_error_free_close(0, NULL,
			"Map Too BIG\n");
	check_iregular(map);
	check_wall(map);
	check_route(map);    // 道筋あるかチェック
}
