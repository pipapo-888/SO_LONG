/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:41:39 by knomura           #+#    #+#             */
/*   Updated: 2025/10/11 17:58:31 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAP_SIZE 100

typedef struct s_map{
	char	**map;
	size_t	player_count;
	size_t	item_count;
	size_t	exit_count;
	size_t	width;
	size_t	height;
} t_map;

int	validate_map(char **map)
{
}

void	read_map(char *map_name)
{
	char	*line;
	int		i;
	size_t	j;
	int		fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error\n", 2);
	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		j = 0;
		while (j < strlen(line))
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
	close(fd);
}

int map_len(char *map_name, t_map *map)
{
	
}

t_map map_init(char *map_name)
{
	t_map map;
	map.map = NULL;
	map.player_count = 0;
	map.item_count = 0;
	map.exit_count = 0;
	map.width = 0;
	map.height = 0;
	map_len(map_name, &map);
	read_map(map_name);
	validate_map(map_name);

	return (map);
}

int	main(int argc, char **argv)
{
	char	map[MAP_SIZE][MAP_SIZE];

	if (argc != 2)
		return (0);
	map_init(argv[1]);

	for (int i = 0; i < 5; i++)
		printf("%s", map[i]);
	return (0);
}
