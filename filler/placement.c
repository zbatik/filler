/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:20:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 12:01:57 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	put(int xi, int yj, t_filler *info, int *score)
{
	int i;
	int j;
	int overlap;

	*score = 0;
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
				{
					*score += info->heatmap[i][j];
					overlap++;
				}
				if (overlap > 1)
					return (0);
			}
			j++;
		}
		i++;
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
	int		i;
	int		j;
	int		success;
	int 	score;
	int		prev_score;

	prev_score = 0;
	score = 0;
	success = 0;
	i = info->limit.top - 1;
	while (++i < info->limit.bottom + 1)
	{
		j = info->limit.left - 1;
		while (++j < info->limit.right + 1)
		{
			if (1 == put(i, j, info, &score))
			{
				success = 1;
				if (comp_score(&prev_score, score))
					set_output(i, j, output, info);
				info->turn++;
			}
		}
	}
	return (success);
}
