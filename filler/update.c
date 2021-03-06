/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/24 14:51:00 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_info(int x, int offset, char **store)
{
	int		i;
	char	*in;

	i = 0;
	while (i < x)
	{
		get_next_line(FD, &in);
		if (in == NULL)
			break ;
		ft_strcpy(store[i], in + offset);
		i++;
		free(in);
	}
	store[i] = 0;
}

void	get_dimension(int *x, int *y, int offset)
{
	char	*line;

	get_next_line(FD, &line);
	*x = ft_atoi(line + offset);
	*y = ft_atoi(line + ft_strlen(ft_itoa(*x)) + offset);
	free(line);
}

void	update_piece(t_filler *info)
{
	char	**piece;
	t_point dim;

	ft_arrdel(&info->piece.data, info->piece.size.x);
	get_dimension(&dim.x, &dim.y, 6);
	piece = ft_arrnew(dim.x, dim.y);
	get_info(dim.x, 0, piece);
	info->piece.offset.x = off_top(piece, dim);
	info->piece.offset.y = off_lef(piece, dim);
	info->piece.size.x = dim.x - info->piece.offset.x - off_bot(piece, dim);
	info->piece.size.y = dim.y - info->piece.offset.y - off_rig(piece, dim);
	info->piece.data = ft_arrnew(info->piece.size.x, info->piece.size.y);
	trim_piece(piece, info);
	ft_arrdel(&piece, dim.x);
}

void	update_data(t_filler *info)
{
	if (info->turn != 0)
		skip_lines(FD, 2);
	get_info(info->map_size.x, 4, info->map);
	update_piece(info);
	update_limit(info);
}
