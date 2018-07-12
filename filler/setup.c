/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:07:23 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/12 13:48:31 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	info->turn = 0;
	info->p1_score = 0;
	info->p2_score = 0;
	update_data(info);
	return (info);
}
