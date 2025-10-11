/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:46 by knomura           #+#    #+#             */
/*   Updated: 2025/10/11 16:32:33 by knomura          ###   ########.fr       */
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

char	*get_next_line(int fd);

#endif
