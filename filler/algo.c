/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:13:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 14:03:24 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	dimond(t_filler *info)
{
	int i;
	int j;
	int heat;

	i = -1;
	while (++i < info->map_size.x)
	{
		j = -1;
		while (++j < info->map_size.y)
		{
			if (i < info->map_size.x / 2)
				heat = i;
			else
				heat = info->map_size.x - i;
			if (j < info->map_size.y / 2)
				heat += j;
			else
				heat += info->map_size.y - j;
			info->heatmap[i][j] = heat;
		}
	}
}

void	left_top(t_filler *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map_size.x)
	{
		j = -1;
		while (++j < info->map_size.y)
		{
			if (0 == ft_strcmp(info->algo, "left_to_right"))	
				info->heatmap[i][j] = j;
			else if (0 == ft_strcmp(info->algo, "top_to_bottom"))
				info->heatmap[i][j] = i;
		}
	}
}

void	update_heatmap(t_filler *info)
{
	fprintf(stderr, "%s\n", info->algo);
	if (0 == ft_strcmp(info->algo, "dimond"))
		dimond(info);
	else if (0 == ft_strcmp(info->algo, "top_to_bottom"))
		left_top(info);
	else if (0 == ft_strcmp(info->algo, "left_to_right"))
		left_top(info);
	else
		dimond(info);
}
