/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/14 17:55:49 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



int put(int xi, int yj, char **map, t_filler *info)
{
	int i;
	int j;
	int overlap;
	
	overlap = 0;
	i = xi;
	while (i < xi + info->piece.x)
	{
		j = yj;
		while (j < yj + info->piece.y)
		{
			if (info->piece.data[i - xi][j - yj] == '*')
			{
				if (map[i][j] == info->player.opp_token)
					return (0);
				if (map[i][j] == info->player.token)
					overlap++;
				map[i][j] = info->player.token; //remove this line
			
			}
			j++;
		}
		i++;
	}
	return (overlap);
}

static void	reset_map(char **map, char **original_map, int x)
{	
	int k;

	k = -1;
	while (++k < x)
		ft_strcpy(map[k], original_map[k]);	
}

int	place(t_filler *info)
{
	int		i;
	int		j;
	int		overlap;
	char	**map;
	
	map = ft_arrnew(info->map_size.x + 1, info->map_size.y + 1);
	update_limit(info);
	i = info->limit.top;
	while (i < info->limit.bottom + 1)
	{
		j = info->limit.left;
		while (j < info->limit.right + 1)
		{
			reset_map(map, info->map, info->map_size.x);
			overlap = put(i, j, map, info);
			if (overlap == 1)
			{
				ft_putstrarr(map);
				print_coords("", i, j);
			}
			j++;
		}
		i++;
	}
//	ft_arrdel(&map);
	return (0);
}
