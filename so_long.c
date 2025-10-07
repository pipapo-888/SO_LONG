/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:41:39 by knomura           #+#    #+#             */
/*   Updated: 2025/10/07 22:55:42 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>


int	main(int argc, char **argv)
{
	char *line;
	
	if (argc != 2)
		return (0);
	int fd;
	fd = open(argv[1], O_RDONLY);

	while (line = get_next_line(fd))
	{
		printf("%s", line);
	}
	


	return (0);
}
