/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:07:23 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 13:11:48 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_player(t_filler *info)
{
	char *line;

	//skip_lines(FD, 0);
	get_next_line(FD, &line);
	
//	info->player.name = player_name;
	info->player.nbr = ft_atoi(10 + line);
	info->player.token = "$OX"[info->player.nbr];
	info->player.opp_token = "$XO"[info->player.nbr];
	/*
	if (ft_strstr(line, player_name) != NULL)
	{
		info->player.nbr = 1;
		info->player.token = P1_TOKEN;
		info->player.opp_token = P2_TOKEN;
		free(line);
	}
	skip_lines(FD, 1);
	get_next_line(FD, &line);
	fprintf(stderr, "%s\n", line);
	if (ft_strstr(line, player_name) != NULL)
	{
		info->player.nbr = 2;
		info->player.token = P2_TOKEN;
		info->player.opp_token = P1_TOKEN;
	}
	else
	{
		info->error = 0;
		perror("Could not find player");
	}
	free(line);
	*/
}

static void set_defaults(t_filler *info)
{
	info->map = NULL;
	info->map_size.x = 0;
	info->map_size.y = 0;
	info->player.nbr = 0;
	info->player.token = '\0';
	info->piece.data = NULL;
	info->piece.x = 0;
	info->piece.y = 0;
	info->turn = 0;
	//info->p1_score = 0;
	//info->p2_score = 0;
	info->limit.left = 0;
	info->limit.right = 0;
	info->limit.top = 0;
	info->limit.bottom = 0;
	info->error = 0;
}

t_filler	*init_data(void)
{
	t_filler	*info;

	info = (t_filler*)malloc(sizeof(t_filler));
	set_defaults(info);
	set_player(info);
	get_dimension(&(info->map_size.x), &(info->map_size.y), 8);
	skip_lines(FD, 1);
	info->map = ft_arrnew(info->map_size.x, info->map_size.y);
	return (info);
}
