/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/10 17:06:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void	store_info(int x, int fd, int offset, char **store)
{
	int		i;
	char	*in;

	i = 0;
	while (i < x)
	{
		get_next_line(fd, &in);
		if (in == NULL)
			break ;
		store[i++] = ft_strdup(in + offset);
		free(in);
	}
	store[i] = 0;
}

void	store_dim(int *x, int *y, int offset, int fd)
{
	char *line;

	get_next_line(fd, &line);
	*x = ft_atoi(line + offset);
	*y = ft_atoi(line + ft_strlen(ft_itoa(*x)) + offset);
	free(line);
}

/*
void update_piece(t_filler *info)
{

}
*/

void	update_score(t_filler *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_size.x)
	{
		j = 0;
		while (j < info->map_size.y)
		{
			if (P1_TOKEN ==	info->map_cur[i][j])
				info->p1_score++;
			else if (P2_TOKEN == info->map_cur[i][j])
				info->p2_score++;
			j++;
		}
		i++;
	}
}

void	update_data(t_filler *info)
{
	store_info(info->map_size.x, FD, 4, info->map_cur);	
	store_dim(&(info->piece.x), &(info->piece.y), 6, FD);
	if (info->piece.cur != NULL)
		free(info->piece.cur);
	printf("HERE\n");
	if (info->piece.x < 1)
		return ;
	info->piece.cur = (char**)malloc(sizeof(char*) * (info->piece.x + 1));	
	store_info(info->piece.x, FD, 0, info->piece.cur);
	update_score(info);
}

void	get_player(t_filler *info)
{	
	char *line;
	skip_lines(FD, 6);
	get_next_line(FD, &line);
	if (ft_strstr(line, PLAYER_NAME) != NULL)
	{
		info->player.nbr = 1;
		info->player.token = P1_TOKEN;
	}
	else
	{
		info->player.nbr = 2;
		info->player.token = P2_TOKEN;
	}
	free(line);
	skip_lines(FD, 2);
}

t_filler	*init_data(void)
{
	t_filler *info;

	info = (t_filler*)malloc(sizeof(t_filler));
	get_player(info);
	store_dim(&(info->map_size.x), &(info->map_size.y), 8, FD);
	skip_lines(FD, 1);
	info->map_cur = (char**)malloc(sizeof(char*) * (info->map_size.x + 1));
	info->piece.cur = NULL;
	update_data(info);
	info->turn = 0;
	info->p1_score = 0;
	info->p2_score = 0;
	print_all_info(info);
	return (info);
}

int		main(void)
{
	t_filler *info;
	int fd;

	fd = open("resources/out_put", O_RDONLY);
	info = init_data();
	
	close(FD);
	print_all_info(info);
}
