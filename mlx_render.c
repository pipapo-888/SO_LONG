/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 02:08:41 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int close_window(void *param)
{
    (void)param; // mlx_destroy_wind　と mlx_destroy_image を追加する
    exit(0);
    return (0);
}

void put_player_to_window_and_info(t_info *info, size_t i, size_t j)
{
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, j * 64, i * 64);
	info->player_info.x = j;
	info->player_info.y = i;
	info->player_info.coin_count = 0;
	info->player_info.move_count = 0;

	printf("x座標は:%ld y座標は:%ld\n", info->player_info.x, info->player_info.y);
}

void put_to_window(t_info *info)
{
	int i;
	int j;

	i = 0;
	while ((size_t)i < info->map_info.height)
	{
		j = 0;
		while ((size_t)j < info->map_info.width)
		{
			if (info->map_info.map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->win, info->images_info.wall, j * 64, i * 64);
			else if (info->map_info.map[i][j] == '0')
				mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, j * 64, i * 64);
			else if (info->map_info.map[i][j] == 'P')
				put_player_to_window_and_info(info, i, j);
			else if (info->map_info.map[i][j] == 'C')
				mlx_put_image_to_window(info->mlx, info->win, info->images_info.item, j * 64, i * 64);
			else if (info->map_info.map[i][j] == 'E')
				mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, j * 64, i * 64);
			j++;
		}
		i++;
	}
}


void init_image(t_info *info)
{
	int img_width;
    int img_height;

	info->images_info.item = mlx_xpm_file_to_image(info->mlx, "./images/z_Coin.xpm", &img_width, &img_height);
	info->images_info.exit = mlx_xpm_file_to_image(info->mlx, "./images/z_Exit.xpm", &img_width, &img_height);
	info->images_info.player = mlx_xpm_file_to_image(info->mlx, "./images/z_Player.xpm", &img_width, &img_height);
	info->images_info.wall = mlx_xpm_file_to_image(info->mlx, "./images/z_Wall.xpm", &img_width, &img_height);
	info->images_info.tile = mlx_xpm_file_to_image(info->mlx, "./images/z_Background.xpm", &img_width, &img_height);
}

void window_render(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->map_info.width * 64, info->map_info.height * 64, "so_long");
	init_image(info);

	put_to_window(info);

	mlx_key_hook(info->win, handle_key, info);
	mlx_hook(info->win, 17, 0, close_window, NULL);

	mlx_loop(info->mlx);
}

