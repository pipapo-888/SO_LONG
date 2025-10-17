/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:08:10 by knomura           #+#    #+#             */
/*   Updated: 2025/10/17 16:43:11 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (0);
	info.map_info = map_init(argv[1]);
	window_render(&info);
	(void)info;
	return (0);
}
