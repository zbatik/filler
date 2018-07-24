/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/24 15:09:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	put(int xi, int yj, t_filler *info, int *score)
{
	t_point c;
	int		overlap;

	overlap = 0;
	c.x = xi - 1;
	while (++c.x < xi + info->piece.size.x)
	{
		c.y = yj - 1;
		while (++c.y < yj + info->piece.size.y)
		{
			if (info->piece.data[c.x - xi][c.y - yj] == '*')
			{
				if (info->map[c.x][c.y] == info->player.token)
				{
					*score += info->heatmap[c.x][c.y];
					overlap++;
				}
				if (info->map[c.x][c.y] == info->player.opp_tok || overlap > 1)
					return (0);
			}
		}
	}
	return (overlap);
}

int	comp_score(int *prev_score, int score)
{
	if (*prev_score <= score)
	{
		*prev_score = score;
		return (1);
	}
	return (0);
}

int	place(t_filler *info, t_point *output)
{
	t_point	count;
	int		success;
	int		score;
	int		prev_score;

	prev_score = 0;
	success = 0;
	count.x = info->limit.top - 1;
	while (++count.x < info->limit.bottom + 1)
	{
		count.y = info->limit.left - 1;
		while (++count.y < info->limit.right + 1)
		{
			score = 0;
			if (1 == put(count.x, count.y, info, &score))
			{
				success = 1;
				if (comp_score(&prev_score, score))
					set_output(count.x, count.y, output, info);
				info->turn++;
			}
		}
	}
	return (success);
}
