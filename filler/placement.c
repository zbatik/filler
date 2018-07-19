/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 16:58:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	put(int xi, int yj, t_filler *info)
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

int	place(t_filler *info)
{
	int		i;
	int		j;
	int		overlap;

	i = info->limit.top;
	while (i < info->limit.bottom + 1)
	{
		j = info->limit.left;
		while (j < info->limit.right + 1)
		{
			overlap = put(i, j, info);
			if (overlap == 1)
			{
				print_coords(i - info->piece.offset.x,
						j - info->piece.offset.y);
				info->turn++;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
