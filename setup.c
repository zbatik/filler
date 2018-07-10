/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:07:23 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/10 17:22:37 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
