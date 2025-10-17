/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:08:10 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 13:41:31 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_info info;
	if (argc != 2)
		return (0);
	info.map_info = map_init(argv[1]);
	window_render(&info);

	(void)info;
	return (0);
}


// cc main.c minilibx-linux/libmlx.a -lXext -lX11

// cc mlx_render.c handle_key.c validate_map.c main.c so_long.c error_message.c GET_NEXT_LINE/gnllib.a LIBFT/libft.a minilibx-linux/libmlx.a -lXext -lX11

// read_mapでマップ読み込み -> mapをValidate -> mlx_init -> new_windows -> 使う ->
