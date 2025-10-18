# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 16:07:52 by knomura           #+#    #+#              #
#    Updated: 2025/10/18 17:53:12 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c map_init.c mlx_render.c validate_map.c check_route.c handle_key.c error_message.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = printf/printf.a
GNL = get_next_line/gnllib.a
MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -lXext -lX11 -o $@

$(LIBFT):
	make -C libft all

$(PRINTF):
	make -C printf all

$(GNL):
	make -C get_next_line all

$(MLX):
	make -C minilibx-linux all

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C printf clean
	make -C get_next_line clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean
	make -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re
