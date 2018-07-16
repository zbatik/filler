/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 13:17:57 by zbatik           ###   ########.fr       */
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
	//	fprintf(stderr, "%s\n", in);
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
/*
void	get_score(int *p1, int *p2, t_point size, char **map)
{
	int i;
	int j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			if (P1_TOKEN ==	map[i][j] || 
					ft_tolower(P1_TOKEN) == map[i][j])
				*p1 += 1;
			else if (P2_TOKEN == map[i][j] ||
					ft_tolower(P2_TOKEN) == map[i][j])
				*p2 += 1;
			j++;
		}
		i++;
	}
}
*/
void	update_data(t_filler *info)
{
	if (info->turn != 0)
		skip_lines(FD, 2);
	get_info(info->map_size.x, 4, info->map);
	//free_piece(info->piece.data);
	get_dimension(&(info->piece.x), &(info->piece.y), 6);
	info->piece.data = ft_arrnew(info->piece.x, info->piece.y);
	get_info(info->piece.x, 0, info->piece.data);
	update_limit(info);
	/* update score */
//	get_score(&(info->p1_score), &(info->p2_score), info->map_size, info->map);
}
