/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:08:10 by knomura           #+#    #+#             */
/*   Updated: 2025/10/18 19:07:55 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_extenstion(char *map_name)
{
	size_t len;
	
	len = ft_strlen(map_name);
	if (len < 5 || ft_strncmp(".ber", map_name + len - 4, 4))
		put_error_free_close(-1, NULL, "Invalid file extension. Must be .ber\n", NULL);	
}
int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		put_error();
	check_extenstion(argv[1]);
	info.map_info = map_init(argv[1]);
	window_render(&info);
	(void)info;
	return (0);
}
