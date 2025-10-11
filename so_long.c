/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:41:39 by knomura           #+#    #+#             */
/*   Updated: 2025/10/11 16:14:30 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAP_SIZE 100

int validate_map(char **map)
{

}

void read_map(char *map_name, char map[MAP_SIZE][MAP_SIZE])
{
	char *line;
	int i;
	size_t j;
	int	fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		write(1 , "", 1);
	while ((line = get_next_line(fd)))
	{
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


int	main(int argc, char **argv)
{
	char map[MAP_SIZE][MAP_SIZE];

	if (argc != 2)
		return (0);
	read_map(argv[1], map);
	for (int i = 0; i < 5; i++)
		printf("%s", map[i]);

	return (0);
}
