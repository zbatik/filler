/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:07:23 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 14:10:28 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_player(t_filler *info)
{
	char	*line;
	int		player_nbr;

	get_next_line(FD, &line);
	player_nbr = ft_atoi(10 + line);
	info->player.token = "$OX"[player_nbr];
	info->player.opp_token = "$XO"[player_nbr];
	free(line);
}

static void	set_defaults(t_filler *info)
{
	info->map = NULL;
	info->map_size.x = 0;
	info->map_size.y = 0;
	info->player.token = '\0';
	info->piece.data = NULL;
	info->piece.size.x = 0;
	info->piece.size.y = 0;
	info->piece.offset.x = 0;
	info->piece.offset.y = 0;
	info->turn = 0;
	info->heatmap = NULL;
	info->limit.left = 0;
	info->limit.right = 0;
	info->limit.top = 0;
	info->limit.bottom = 0;
	info->last_play.x = 0;
	info->last_play.y = 0;
	info->algo = "";
}

static void	select_algo(t_filler *info)
{
	int 	fd;
	int		ret;
	char	*line;

	fd = open("select_strategy.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret != -1)
	{
		fprintf(stderr, "%s\n", line);
		info->algo = line;
		free(line);
	}
	else
		info->algo = "dimond";
	close(fd);
}

t_filler	*init_data(void)
{
	int			i;
	t_filler	*info;

	info = (t_filler*)malloc(sizeof(t_filler));
	set_defaults(info);
	set_player(info);
	get_dimension(&(info->map_size.x), &(info->map_size.y), 8);
	skip_lines(FD, 1);
	info->map = ft_arrnew(info->map_size.x, info->map_size.y);
	info->heatmap = (int **)malloc(sizeof(int*) * info->map_size.x);
	i = -1;
	select_algo(info);
	while (++i < info->map_size.x)
		info->heatmap[i] = (int*)malloc(sizeof(int) * info->map_size.y);
	return (info);
	update_heatmap(info);
}
