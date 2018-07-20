/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/20 16:47:54 by zbatik           ###   ########.fr       */
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

int ft_pow(int n, int m)
{
	int ret;

	ret = 1;
	while (m >= 0)
	{
		ret *= n;
		m--;
	}
	return (ret);
}

void	set_output(int i, int j, t_point *output, t_filler *info)
{
	output->x = i - info->piece.offset.x;
	output->y = j - info->piece.offset.y;
}

int	dist(t_point A, t_point B)
{
	return (ft_pow(A.x - B.x, 2) + ft_pow(A.y - B.y, 2));
}

void	rank_output(int i, int j, t_point *output, t_filler *info)
{
	t_point check;
	t_point last_play;

	last_play = info->last_play;
	check.x = i;
	check.y = j; 
	if (dist(last_play, check) > dist(*output, last_play))
		set_output(i, j, output, info);
}

int	place(t_filler *info, t_point *output)
{
	int		i;
	int		j;
	int		overlap;
	int		success;

	success = 0;
	i = info->limit.top;
	while (i < info->limit.bottom + 1)
	{
		j = info->limit.left;
		while (j < info->limit.right + 1)
		{
			overlap = put(i, j, info);
			if (overlap == 1)
			{
				if (success == 0)
					set_output(i, j, output, info);
				success = 1;
				rank_output(i, j, output, info);
				info->turn++;
			}
			j++;
		}
		i++;
	}
	return (success);
}
