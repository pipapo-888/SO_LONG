/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 16:12:40 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}
void put_to_window(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_info.height)
	{
		j = 0;
		while (j < info->map_info.width)
		{
		if (info->map_info.map[i][j] == '1')
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.wall, j * 64, i * 64);
		else if (info->map_info.map[i][j] == '0')
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, j * 64, i * 64);
		else if (info->map_info.map[i][j] == 'P')
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, j * 64, i * 64);
		else if (info->map_info.map[i][j] == 'C')
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.item, j * 64, i * 64);
		else if (info->map_info.map[i][j] == 'E')
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}


void init_image(t_info *info)
{
	int img_width;
    int img_height;

	info->images_info.item = mlx_xpm_file_to_image(info->mlx, "./z_Coin.xpm", &img_width, &img_height);
	info->images_info.exit = mlx_xpm_file_to_image(info->mlx, "./z_Exit.xpm", &img_width, &img_height);
	info->images_info.player = mlx_xpm_file_to_image(info->mlx, "./z_Player.xpm", &img_width, &img_height);
	info->images_info.wall = mlx_xpm_file_to_image(info->mlx, "./z_Wall.xpm", &img_width, &img_height);
	info->images_info.tile = mlx_xpm_file_to_image(info->mlx, "./z_Background.xpm", &img_width, &img_height);
}

void window_render(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->map_info.width * 64, info->map_info.height * 64, "so_long");
	init_image(info);
	put_to_window(info);

	// mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, 0, 64);
	// mlx_put_image_to_window(info->mlx, info->win, info->images_info.item, 0, 0);
	// mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, 64, 0);
	// mlx_put_image_to_window(info->mlx, info->win, info->images_info.wall, 128, 0);
	// mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, 192, 0);




	mlx_hook(info->win, 17, 0, close_window, NULL);
	mlx_loop(info->mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
