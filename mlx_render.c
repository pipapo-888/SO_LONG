/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 15:02:03 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

void init_image(t_info *info)
{
	int img_width;
    int img_height;

	info->images_info.item = mlx_xpm_file_to_image(info->mlx, "./resized_penguin.xpm", &img_width, &img_height);
	info->images_info.player = mlx_xpm_file_to_image(info->mlx, "./Dolphin.xpm", &img_width, &img_height);
	info->images_info.exit = mlx_xpm_file_to_image(info->mlx, "./z_c.xpm", &img_width, &img_height);

}

void window_render(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->map_info.width * 64, info->map_info.height * 64, "so_long");
	init_image(info);

	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, 0, 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.item, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, 64, 0);




	mlx_hook(info->win, 17, 0, close_window, NULL);
	mlx_loop(info->mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
