/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 16:44:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void put(int xi, int yj, char **map, t_filler *info)
{
	int i;
	int j;
	
	i = xi;
	while (i < xi + info->piece.x)
	{
		j = yj;
		while (j < yj + info->piece.y + 1)
		{
			if (info->piece.data[xi - i][yj - j] == '*')
			{	
				//map[i][j] = info->player.token;
				map[i][j] = 'B';
			}
			j++;
		}
		i++;
	}
}

int place(t_filler *info)
{
	int		i;
	int		j;
	//t_point	ret;
	char	**map;
	
	map = ft_arrnew(info->map_size.x + 1, info->map_size.y + 1);
	update_limit(info);
	i = -1;
	while (++i < info->map_size.x)
		ft_strcpy(map[i], info->map[i]);
	i = info->limit.top;
	while (i < info->limit.bottom + 1)
	{
		j = info->limit.left;
		while (j < info->limit.right + 1)
		{
			put(i, j, map, info);
			printf("i: %d j: %d\n",i, j);
			ft_putstrarr(map);
			j++;
		}
		i++;
	}
	return (0);
}
