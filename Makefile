# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 16:07:52 by knomura           #+#    #+#              #
#    Updated: 2025/10/17 13:34:13 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c so_long.c mlx_render.c validate_map.c handle_key.c error_message.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT = LIBFT/libft.a
PRINTF = PRINTF/printf.a
GNL = GET_NEXT_LINE/gnllib.a
MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -lXext -lX11 -o $@

$(LIBFT):
	make -C LIBFT all

$(PRINTF):
	make -C PRINTF all

$(GNL):
	make -C GET_NEXT_LINE all

$(MLX):
	make -C minilibx-linux all

clean:
	rm -f $(OBJ)
	make -C LIBFT clean
	make -C PRINTF clean
	make -C GET_NEXT_LINE clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean
	make -C PRINTF fclean
	make -C GET_NEXT_LINE fclean

re: fclean all

.PHONY: all clean fclean re
