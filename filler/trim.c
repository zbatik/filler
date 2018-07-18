/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:45:57 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/18 17:10:52 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void offset_top(t_piece *piece)
{
	int i;
	int j;

	i = -1;
	while (++i < piece->size.x)
	{
		j = -1;
		while (++j < piece->size.y)
		{
			if (piece->data[i][j] == '*')
			{	
				piece->offset.x = i;
				return ;
			}
		}
	}
}

static int offset_bottom(t_piece piece)
{
	int i;
	int j;

	i = piece->size.x;
	while (--i >= 0)
	{
		j = piece->size.y;
		while (--j >= 0)
		{
			if (piece->data[i][j] == "*")
				return (i);
		}
	}
}

static void offset_left(t_piece piece)
{
	int i;
	int j;

	j = -1;
	while (++j < piece->size.y)
	{
		i = -1;
		while (++i < piece->size.x)
		{
			if (piece->data[i][j] == "*")
			{
				piece->offset.y = i;	
				return ;
			}
		}
	}
}

static int offset_right(t_piece *piece)
{
	int i;
	int j;

	j = piece->size.y;
	while (--j >= 0)
	{
		i = piece->size.x;
		while (--i >= 0)
		{
			if (piece->data[i][j] == "*")
			{	
				return (i);
			}
		}
	}
}

void trim_piece(t_filler *info)
{
	int off_bot;
	int off_right;

	offset_top(&info->piece);
	off_bot = offset_bottom(&info->piece);
	offset_left(&info->piece);
	off_right = offset_right(&info->piece);

}
