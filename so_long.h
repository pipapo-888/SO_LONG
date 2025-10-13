/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:46 by knomura           #+#    #+#             */
/*   Updated: 2025/10/13 18:31:36 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

# include "LIBFT/libft.h"
# include "GET_NEXT_LINE/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_map{
	char	**map;
	size_t	player_count;
	size_t	coin_count;
	size_t	exit_count;
	size_t	width;
	size_t	height;
	size_t exit_x;
	size_t exit_y;
} t_map;

typedef struct s_player{
	size_t	x;
	size_t	y;
	size_t	coin_count;
	size_t	move_count;
}t_player;

typedef struct s_images{
	void	*tile;
	void	*wall;
	void	*item;
	void	*exit;
	void	*player;
	int		size;
}t_images;

typedef struct s_info{
	void		*mlx;
	void		*win;
	t_map		map_info;
	t_player	player_info;
	t_images	images_info;
}t_info;

t_map	map_init(char *map_name);

void	window_render(t_info *info);

void 	put_error();
void	put_error_free_close(int fd, char *line, char *message);


#endif
