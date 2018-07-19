/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:45:57 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 16:27:45 by zbatik           ###   ########.fr       */
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
	perror("invalid piece");
	return (-1);
}

int offset_bottom(char **piece, t_point dim)
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
	perror("invalid piece");
	return (-1);
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
				return (j);
		}
	}
	perror("invalid piece");
	return (-1);
}

int offset_right(char **piece, t_point dim)
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
		count ++;
	}
	perror("invalid piece");
	return (-1);
}

void trim_piece(char **piece, t_filler *info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->piece.size.x)
	{
		j = -1;
		while (++j < info->piece.size.y)
			info->piece.data[i][j] = piece[i + info->piece.offset.x][ j + info->piece.offset.y];
	}
}
