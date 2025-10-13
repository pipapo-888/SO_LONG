/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 12:03:12 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_render(t_info *info)
{
	void *mlx;
	void *win;
	void *penguin_pic;
	int img_width;
    int img_height;


	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 800, 800, "so_long");

	penguin_pic = mlx_xpm_file_to_image(info->mlx, "./penguin.xpm", &img_width, &img_height);
	mlx_put_image_to_window(info->mlx, info->win, penguin_pic, 0, 0);

	mlx_loop(info->mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
