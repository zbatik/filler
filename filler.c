/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/09 18:41:08 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	write(1, "7 ", 3);
	/*int fd;
	int i;
	char *in;
	filler *info;

	fd = open("sample_out", O_RDONLY);
	i = -1;
	while (++i < 5)
	{
		get_next_line(fd, &in);
		printf("%s\n", in);
		free(in);
	}
	info = (filler*)malloc(sizeof(filler));
	get_next_line(fd, &in);
	info->map_dim.x = ft_atoi(in + 8);
	info->map_dim.y = ft_atoi(in + 8 + ft_strlen(ft_itoa(info->map_dim.x)));
	printf("x: %d, y: %d\n", info->map_dim.x, info->map_dim.y);
	close(fd);*/
}
