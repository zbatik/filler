/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:45:57 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 12:09:30 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		off_top(char **piece, t_point dim)
{
	int i;

	i = -1;
	while (++i < dim.x)
	{
		if (ft_element('*', piece[i]))
			return (i);
	}
	return (-1);
}

int		off_bot(char **piece, t_point dim)
{
	int i;
	int count;

	count = 0;
	i = dim.x;
	while (--i >= 0)
	{
		if (ft_element('*', piece[i]))
			return (count);
		count++;
	}
	return (-1);
}

int		off_lef(char **piece, t_point dim)
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
				return (j);
		}
	}
	return (-1);
}

int		off_rig(char **piece, t_point dim)
{
	int i;
	int j;
	int count;

	j = dim.y;
	count = 0;
	while (--j >= 0)
	{
		i = dim.x;
		while (--i >= 0)
		{
			if (piece[i][j] == '*')
				return (count);
		}
		count++;
	}
	return (-1);
}

void	trim_piece(char **piece, t_filler *info)
{
	int			i;
	int			j;
	t_point		off;

	off = info->piece.offset;
	i = -1;
	while (++i < info->piece.size.x)
	{
		j = -1;
		while (++j < info->piece.size.y)
			info->piece.data[i][j] = piece[i + off.x][j + off.y];
	}
}
