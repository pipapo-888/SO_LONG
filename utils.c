/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:37 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 02:17:54 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while ((size_t)i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void free_map_copy(char **map_copy, int height)
{
    int i;
	
    for (i = 0; i < height; i++)
    {
        free(map_copy[i]);
    }

    free(map_copy);
}

void free_all_exit(t_info *info)
{
	int	i;

	mlx_destroy_image(info->mlx, info->images_info.tile);
	mlx_destroy_image(info->mlx, info->images_info.wall);
	mlx_destroy_image(info->mlx, info->images_info.item);
	mlx_destroy_image(info->mlx, info->images_info.exit);
	mlx_destroy_image(info->mlx, info->images_info.player);
	mlx_destroy_window(info->mlx, info->win);

	i = 0;
	while ((size_t)i < info->map_info.height)
	{
		free(info->map_info.map[i]);
		i++;
	}
	free(info->map_info.map);
	exit(0);
}