/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:45:57 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 16:44:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	limit_top(t_filler *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map_size.x)
	{
		j = -1;
		while (++j < info->map_size.y)
		{
			if (info->map[i][j] == info->player.token)
			{
				info->limit.top = ft_max(0, i - (info->piece.size.x - 1));
				return ;
			}
		}
	}
}

static void	limit_bottom(t_filler *info)
{
	int		i;
	int		j;
	t_point	ps;

	ps = info->piece.size;
	i = info->map_size.x;
	while (--i >= 0)
	{
		j = info->map_size.y;
		while (--j >= 0)
		{
			if (info->map[i][j] == info->player.token)
			{
				info->limit.bottom = ft_min(i, info->map_size.x - ps.x);
				return ;
			}
		}
	}
}

static void	limit_left(t_filler *info)
{
	int i;
	int j;

	j = -1;
	while (++j < info->map_size.y)
	{
		i = -1;
		while (++i < info->map_size.x)
		{
			if (info->map[i][j] == info->player.token)
			{
				info->limit.left = ft_max(0, j - (info->piece.size.y - 1));
				return ;
			}
		}
	}
}

static void	limit_right(t_filler *info)
{
	int		i;
	int		j;
	t_point ps;

	ps = info->piece.size;
	j = info->map_size.y;
	while (--j >= 0)
	{
		i = info->map_size.x;
		while (--i >= 0)
		{
			if (info->map[i][j] == info->player.token)
			{
				info->limit.right = ft_min(j, info->map_size.y - ps.y);
				return ;
			}
		}
	}
}

void		update_limit(t_filler *info)
{
	limit_top(info);
	limit_bottom(info);
	limit_left(info);
	limit_right(info);
}
