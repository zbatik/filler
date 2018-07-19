/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:45:57 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 15:20:00 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int offset_top(char **piece, t_point dim)
{
	int i;

	i = -1;
	while (++i < dim.x)
	{
		if (ft_element('*', piece[i]))
			return (i);
	}
	return (i);
}

int offset_bottom(char **piece, t_point dim)
{
	int i;

	i = dim.x;
	while (--i >= 0)
	{
		if (ft_element('*', piece[i]))
			return (i);
	}
	return (i);
}

int	offset_left(char **piece, t_point dim)
{
	int		i;
	int		j;

	j = -1;
	while (++j < dim.y)
	{
		i = -1;
		while (++i < dim.x)
		{
			if (piece[i][j] == '*')
				return (i);
		}
	}
	return (i);
}

int offset_right(char **piece, t_point dim)
{
	int i;
	int j;

	j = dim.y;
	while (--j >= 0)
	{
		i = dim.x;
		while (--i >= 0)
		{
			if (piece[i][j] == '*')
				return (i);
		}
	}
	return (i);
}

void trim_piece(char **piece, t_point dim, t_filler *info)
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
