/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 12:31:55 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void window_render(t_info *info)
{
	void *penguin_pic;
	int img_width;
    int img_height;

	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->map_info.width * 100, info->map_info.height * 100, "so_long");

	penguin_pic = mlx_xpm_file_to_image(info->mlx, "./resized_penguin.xpm", &img_width, &img_height);
	mlx_put_image_to_window(info->mlx, info->win, penguin_pic, 0, 0);

	mlx_loop(info->mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
