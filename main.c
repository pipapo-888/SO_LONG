/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:08:10 by knomura           #+#    #+#             */
/*   Updated: 2025/10/11 16:08:14 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main (){
	void *mlx;
	void *win;
	void *penguin_pic;
	int img_width = 50;
    int img_height = 2000;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "so_long");

	penguin_pic = mlx_xpm_file_to_image(mlx, "./penguin.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, penguin_pic, 0, 0);

	mlx_loop(mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11


// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->

// マップ最大サイズ決まってるか
