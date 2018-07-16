/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 13:13:44 by zbatik           ###   ########.fr       */
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
				if (overlap > 1)
					return (0);
				if (DEBUG) { map[i][j] = info->player.token; }
			
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
	map[k] = NULL;
}

int	place(t_filler *info)
{
	int		i;
	int		j;
	int		overlap;
	char	**map;
	
	map = ft_arrnew(info->map_size.x, info->map_size.y);
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
				if (DEBUG) {ft_putstrarr(map);}
				print_coords("", i, j);
				//fprintf(stderr, "%d %d\n", i, j);
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
