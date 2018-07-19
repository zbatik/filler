/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 16:30:21 by zbatik           ###   ########.fr       */
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

	get_dimension(&dim.x, &dim.y, 6);
	piece = ft_arrnew(dim.x, dim.y);
	get_info(dim.x, 0, piece);
	put_error_arr(piece);
	fprintf(stderr, "dim x: %d\n" , dim.x);
	fprintf(stderr, "dim y: %d\n" , dim.y);
	fprintf(stderr, "top: %d\n" , offset_top(piece, dim));
	fprintf(stderr, "bottom: %d\n" , offset_bottom(piece, dim));
	fprintf(stderr, "left: %d\n" , offset_left(piece, dim));
	fprintf(stderr, "right: %d\n" , offset_right(piece, dim));
	info->piece.offset.x = offset_top(piece, dim);
	info->piece.offset.y = offset_left(piece, dim);
	info->piece.size.x = dim.x - info->piece.offset.x - offset_bottom(piece, dim);
	info->piece.size.y = dim.y - info->piece.offset.y - offset_right(piece, dim);
	info->piece.data = ft_arrnew(info->piece.size.x, info->piece.size.y);
	//info->piece.size.y = dim.y;
	//info->piece.data = piece;
	trim_piece(piece, info);
	print_piece(info);
	//ft_arrdel(piece);
}

void	update_data(t_filler *info)
{
	if (info->turn != 0)
		skip_lines(FD, 2);
	get_info(info->map_size.x, 4, info->map);
	update_piece(info);
	//print_map(info);
	//print_piece(info);
	update_limit(info);
}
