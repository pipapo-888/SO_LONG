# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 16:07:52 by knomura           #+#    #+#              #
#    Updated: 2025/10/16 18:22:54 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c so_long.c mlx_render.c validate_map.c handle_key.c error_message.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT = LIBFT/libft.a
PRINTF = PRINTF/printf.a

all = $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) ./GET_NEXT_LINE/gnllib.a -o $@

$(LIBFT):
	make -C LIBFT

$(PRINTF):
	make -C PRINTF

clean:
	rm -f $(OBJ)
	make -C LIBFT clean
	make -C PRINTF clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean
	make -C PRINTF fclean

re: fclean all

.PHONY: all clean fclean re bonus
