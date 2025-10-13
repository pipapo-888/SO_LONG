/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:33:51 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 20:43:44 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100


int close_window(void *param)
{
    (void)param; // mlx_destroy_wind　と mlx_destroy_image を追加する
    exit(0);
    return (0);
}

void move_up(t_info *info)
{
	int new_y = info->player_info.y - 1;
	if (info->map_info.map[new_y][info->player_info.x] == '1')
		return ;
	if (info->map_info.map[new_y][info->player_info.x] == 'E'
		&& info->player_info.coin_count == info->map_info.coin_count)
		exit(0); //　ここもしっかりと終了するように変える    MoveCount も表示する必要があるかも
	if (info->map_info.map[new_y][info->player_info.x] == 'C')
	{
		info->player_info.coin_count++;
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, info->map_info.exit_x * 64, info->map_info.exit_y * 64);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, info->player_info.x * 64, new_y * 64);
	info->player_info.move_count++;
	info->player_info.y--;
	printf("Move Count:%ld\n", info->player_info.move_count);

	// printf("yes\n");
	// printf("%p\n", info->images_info.player);
	// if (!info->images_info.player)
	// {
   	// 	printf("player image is NULL!\n");
    // 	return;
	// }
	// if (!info->mlx || !info->win)
	// {
    // 	printf("mlx or win is NULL!\n");
    // 	return;
	// }
	// // put_to_window(info);
	// // mlx_put_image_to_window(info->mlx, info->win, info->images_info.player, 0, 0);
}

void move_down(t_info *info)
{
	if (info->map_info.map[info->player_info.y + 1][info->player_info.x] == '1')
		return ;
	if (info->map_info.map[info->player_info.y + 1][info->player_info.x] == 'E' && info->player_info.coin_count == info->map_info.coin_count)
		exit(0); //　ここもしっかりと終了するように変える    MoveCount も表示する必要があるかも
	if (info->map_info.map[info->player_info.y + 1][info->player_info.x] == 'C')
	{
		info->player_info.coin_count++;
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, info->map_info.exit_x * 64, info->map_info.exit_y * 64);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, info->player_info.x * 64, (info->player_info.y + 1) * 64);
	info->player_info.move_count++;
	info->player_info.y++;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

void move_left(t_info *info)
{
	if (info->map_info.map[info->player_info.y][info->player_info.x - 1] == '1')
		return ;
	if (info->map_info.map[info->player_info.y][info->player_info.x - 1] == 'E' && info->player_info.coin_count == info->map_info.coin_count)
		exit(0); //　ここもしっかりと終了するように変える    MoveCount も表示する必要があるかも
	if (info->map_info.map[info->player_info.y][info->player_info.x - 1] == 'C')
	{
		info->player_info.coin_count++;
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, info->map_info.exit_x * 64, info->map_info.exit_y * 64);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, (info->player_info.x - 1) * 64, (info->player_info.y) * 64);
	info->player_info.move_count++;
	info->player_info.x--;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

void move_right(t_info *info)
{
	if (info->map_info.map[info->player_info.y][info->player_info.x + 1] == '1')
		return ;
	if (info->map_info.map[info->player_info.y][info->player_info.x + 1] == 'E' && info->player_info.coin_count == info->map_info.coin_count)
		exit(0); //　ここもしっかりと終了するように変える    MoveCount も表示する必要があるかも
	if (info->map_info.map[info->player_info.y][info->player_info.x + 1] == 'C')
	{
		info->player_info.coin_count++;
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win, info->images_info.exit, info->map_info.exit_x * 64, info->map_info.exit_y * 64);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile, (info->player_info.x + 1) * 64, (info->player_info.y) * 64);
	info->player_info.move_count++;
	info->player_info.x++;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

int handle_key(int keycode, t_info *info)
{
	// printf("%d\n", keycode);
    if (keycode == KEY_ESC)
    {
        // mlx_destroy_window(info->mlx, info->win);
        exit(0);
    }
	if (keycode == KEY_W)
	{
		printf("inhere\n");
		move_up(info);
	}
	if (keycode == KEY_A)
		move_left(info);
	if (keycode == KEY_S)
		move_down(info);
	if (keycode == KEY_D)
		move_right(info);
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
	printf("二回目");

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


	mlx_key_hook(info->win, handle_key, info);
	mlx_hook(info->win, 17, 0, close_window, NULL);

	mlx_loop(info->mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
