/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:13:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/24 14:51:17 by zbatik           ###   ########.fr       */
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

void	cross(t_filler *info)
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
			if (i == j)
				heat = info->map_size.x;
			else if (i + j == ft_max(info->map_size.x, info->map_size.y))
				heat = info->map_size.x;
			else if (j != 0)
				heat = ft_abs(info->heatmap[i][j - 1] - 1);
			else
				heat = 0;
			info->heatmap[i][j] = heat;
		}
	}
}

void	side_to_side(t_filler *info)
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
				info->heatmap[i][j] = info->map_size.y - j;
			else if (0 == ft_strcmp(info->algo, "top_to_bottom"))
				info->heatmap[i][j] = info->map_size.x - i;
			else if (0 == ft_strcmp(info->algo, "right_to_left"))
				info->heatmap[i][j] = j;
			else if (0 == ft_strcmp(info->algo, "bottom_to_top"))
				info->heatmap[i][j] = i;
		}
	}
}

void	update_heatmap(t_filler *info)
{
	if (0 == ft_strcmp(info->algo, "dimond"))
		dimond(info);
	else if (0 == ft_strcmp(info->algo, "cross"))
		cross(info);
	else if (0 == ft_strcmp(info->algo, "top_to_bottom"))
		side_to_side(info);
	else if (0 == ft_strcmp(info->algo, "left_to_right"))
		side_to_side(info);
	else if (0 == ft_strcmp(info->algo, "right_to_left"))
		side_to_side(info);
	else if (0 == ft_strcmp(info->algo, "bottom_to_top"))
		side_to_side(info);
	else
		dimond(info);
}
