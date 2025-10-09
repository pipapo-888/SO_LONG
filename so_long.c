/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:41:39 by knomura           #+#    #+#             */
/*   Updated: 2025/10/10 01:15:15 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void read_map(char *map_name, char map[20][20])
{
	char *line;
	int i;
	size_t j;
	int	fd;
	
	i = 0;
	fd = open(map_name, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		j = 0;
		// printf("%s", line);
		while (j < strlen(line))
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	char map[20][20];
		
	if (argc != 2)
		return (0);
		
	read_map(argv[1], map);
	for (int i = 0; i < 5; i++)
		printf("%s", map[i]);
	return (0);
}
