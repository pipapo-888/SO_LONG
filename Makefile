# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 16:07:52 by knomura           #+#    #+#              #
#    Updated: 2025/10/17 02:42:37 by knomura          ###   ########.fr        #
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
MLX = minilibx/libmlx.a

all = $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -lXext -lX11 -o $@

$(LIBFT):
	make -C LIBFT

$(PRINTF):
	make -C PRINTF

$(GNL):
	make -C GET_NEXT_LINE

$(MLX):
	make -C minilibx

clean:
	rm -f $(OBJ)
	make -C LIBFT clean
	make -C PRINTF clean
	make -C GET_NEXT_LINE clean
	make -C minilibx clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean
	make -C PRINTF fclean
	make -C GET_NEXT_LINE fclean
	make -C minilibx fclean

re: fclean all

.PHONY: all clean fclean re