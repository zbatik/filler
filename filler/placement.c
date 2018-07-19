/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 16:15:59 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int put(int xi, int yj, t_filler *info)
{
	int i;
	int j;
	int overlap;
	
	overlap = 0;
	i = xi;
	while (i < xi + info->piece.size.x)
	{
		j = yj;
		while (j < yj + info->piece.size.y)
		{
			if (info->piece.data[i - xi][j - yj] == '*')
			{
				if (info->map[i][j] == info->player.opp_token)
					return (0);
				if (info->map[i][j] == info->player.token)
					overlap++;
				if (overlap > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (overlap);
}
/*
static void	reset_map(char **map, char **original_map, int x)
{	
	int k;

	k = -1;
	while (++k < x)
		ft_strcpy(map[k], original_map[k]);
	map[k] = NULL;
}
*/
int	place(t_filler *info)
{
	int		i;
	int		j;
	int		overlap;
	
	//update_limit(info);
	i = info->limit.top;
	while (i < info->limit.bottom + 1)
	{
		j = info->limit.left;
		while (j < info->limit.right + 1)
		{
			overlap = put(i, j, info);
			if (overlap == 1)
			{
				print_coords("", i - info->piece.offset.x, j - info->piece.offset.y);
				info->turn++;
				return (1);	
			}
			j++;
		}
		i++;
	}
//	ft_arrdel(&map); // currently not working - re work ft_arrdel
	return (0);
}
