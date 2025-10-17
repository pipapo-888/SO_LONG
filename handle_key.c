/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:59:15 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 13:05:58 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

void	move_up(t_info *info)
{
	int	new_y;

	new_y = info->player_info.y - 1;
	if (info->map_info.map[new_y][info->player_info.x] == '1')
		return ;
	if (info->map_info.map[new_y][info->player_info.x] == 'E'
		&& info->player_info.coin_count == info->map_info.coin_count)
		free_all_exit(info);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile,
		info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player,
		info->player_info.x * 64, new_y * 64);
	if (info->map_info.map[new_y][info->player_info.x] == 'C')
	{
		info->player_info.coin_count++;
		info->map_info.map[new_y][info->player_info.x] = '0';
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win,
				info->images_info.exit, info->map_info.exit_x * 64,
				info->map_info.exit_y * 64);
	}
	info->player_info.move_count++;
	info->player_info.y--;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

void	move_down(t_info *info)
{
	int	new_y;

	new_y = info->player_info.y + 1;
	if (info->map_info.map[new_y][info->player_info.x] == '1')
		return ;
	if (info->map_info.map[new_y][info->player_info.x] == 'E'
		&& info->player_info.coin_count == info->map_info.coin_count)
		free_all_exit(info);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile,
		info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player,
		info->player_info.x * 64, new_y * 64);
	if (info->map_info.map[new_y][info->player_info.x] == 'C')
	{
		info->player_info.coin_count++;
		info->map_info.map[new_y][info->player_info.x] = '0';
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win,
				info->images_info.exit, info->map_info.exit_x * 64,
				info->map_info.exit_y * 64);
	}
	info->player_info.move_count++;
	info->player_info.y++;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

void	move_left(t_info *info)
{
	int	new_x;

	new_x = info->player_info.x - 1;
	if (info->map_info.map[info->player_info.y][new_x] == '1')
		return ;
	if (info->map_info.map[info->player_info.y][new_x] == 'E'
		&& info->player_info.coin_count == info->map_info.coin_count)
		free_all_exit(info);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile,
		info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player,
		new_x * 64, info->player_info.y * 64);
	if (info->map_info.map[info->player_info.y][new_x] == 'C')
	{
		info->player_info.coin_count++;
		info->map_info.map[info->player_info.y][new_x] = '0';
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win,
				info->images_info.exit, info->map_info.exit_x * 64,
				info->map_info.exit_y * 64);
	}
	info->player_info.move_count++;
	info->player_info.x--;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

void	move_right(t_info *info)
{
	int	new_x;

	new_x = info->player_info.x + 1;
	if (info->map_info.map[info->player_info.y][new_x] == '1')
		return ;
	if (info->map_info.map[info->player_info.y][new_x] == 'E'
		&& info->player_info.coin_count == info->map_info.coin_count)
		free_all_exit(info);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.tile,
		info->player_info.x * 64, info->player_info.y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->images_info.player,
		new_x * 64, info->player_info.y * 64);
	if (info->map_info.map[info->player_info.y][new_x] == 'C')
	{
		info->player_info.coin_count++;
		info->map_info.map[info->player_info.y][new_x] = '0';
		if (info->player_info.coin_count == info->map_info.coin_count)
			mlx_put_image_to_window(info->mlx, info->win,
				info->images_info.exit, info->map_info.exit_x * 64,
				info->map_info.exit_y * 64);
	}
	info->player_info.move_count++;
	info->player_info.x++;
	printf("Move Count:%ld\n", info->player_info.move_count);
}

int	handle_key(int keycode, t_info *info)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(info->mlx, info->images_info.tile);
		mlx_destroy_image(info->mlx, info->images_info.wall);
		mlx_destroy_image(info->mlx, info->images_info.item);
		mlx_destroy_image(info->mlx, info->images_info.exit);
		mlx_destroy_image(info->mlx, info->images_info.player);
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (keycode == KEY_W)
		move_up(info);
	if (keycode == KEY_A)
		move_left(info);
	if (keycode == KEY_S)
		move_down(info);
	if (keycode == KEY_D)
		move_right(info);
	return (0);
}
