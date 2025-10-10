#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main (){
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");

	mlx_loop(mlx);
}

// cc main.c minilibx-linux/libmlx.a -lXext -lX11