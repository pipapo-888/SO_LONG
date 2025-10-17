/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:41:39 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 15:59:07 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map_name, t_map *map)
{
	char	*line;
	size_t	i;
	size_t	j;
	int		fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error\n", 2);
	while (i < map->height)
	{
		line = get_next_line(fd);
		j = 0;
		while (j < map->width)
		{
			map->map[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
	}
	close(fd);
}

void	map_len(char *map_name, t_map *map)
{
	int		fd;
	char	*line;
	size_t	len;

	map->width = 0;
	map->height = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		put_error();
	line = get_next_line(fd);
	while (line)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		if (map->width == 0)
			map->width = len;
		else if (map->width != len)
			put_error_free_close(fd, line, "Not Rectangular\n", map);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

t_map	map_init(char *map_name)
{
	t_map	map;
	size_t	i;

	map.map = NULL;
	map.player_count = 0;
	map.coin_count = 0;
	map.exit_count = 0;
	map_len(map_name, &map);
	map.map = malloc(sizeof(char *) * (map.height + 1));
	if (!map.map)
		put_error();
	map.map[map.height] = NULL;
	i = 0;
	while (i < map.height)
	{
		map.map[i] = malloc(sizeof(char) * (map.width + 1));
		if (!map.map[i])
			put_error();
		map.map[i][map.width] = '\0';
		i++;
	}
	read_map(map_name, &map);
	validate_map(&map);
	return (map);
}
