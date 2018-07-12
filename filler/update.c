/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/12 14:39:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	store_map(int x, char **store)
{
	int		i;
	char	*in;

	i = 0;
	while (i < x)
	{
		get_next_line(FD, &in);
		if (in == NULL)
			break ;
		ft_strcpy(store[i], in + 4);
		i++;
		free(in);
	}
	store[i] = 0;
}

void	store_piece(int x, int y, t_filler info)
{
	int		i;
	char	*in;
	char	**tmp[x][y];

	i = 0;
	while (i < x)
	{
		get_next_line(FD, &in);
		if (in == NULL)
			break ;
		ft_strcpy(tmp[i], in);
		i++;
		free(in);
	}
	tmp[i] = 0;
	info->piece.cur = trim_piece(tmp);
}

char	**trim_piece(int x, int y, char **piece)
{
	int i;
	int j;
	int offset[4];

	i = 0;
	offset[0] = 0;
	while (i < x)
	{
		if (0 == ft_element('*', piece[i++]))
			offset[0]++;
		else
			break ;
	}
	i = x - 1;
	offset[1] = 0;
	while (i >= 0)
	{
		if (0 == ft_element('*', piece[i--]))
			offset[2]++;
		else
			break ;
	}
	i = 0;
	offset[2] = 0;
	offset[3] = 0;
	info->piece.cur = (char**)malloc(sizeof(char*) * (x - (offset[0] + offset[1]) + 1));
	while 
}

void	store_dim(int *x, int *y, int offset)
{
	char *line;

	get_next_line(FD, &line);
	*x = ft_atoi(line + offset);
	*y = ft_atoi(line + ft_strlen(ft_itoa(*x)) + offset);
	free(line);
}

void	update_score(t_filler *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_size.x)
	{
		j = 0;
		while (j < info->map_size.y)
		{
			if (P1_TOKEN ==	info->map_cur[i][j] || 
					ft_tolower(P1_TOKEN) == info->map_cur[i][j])
				info->p1_score++;
			else if (P2_TOKEN == info->map_cur[i][j] ||
					ft_tolower(P2_TOKEN) == info->map_cur[i][j])
				info->p2_score++;
			j++;
		}
		i++;
	}
}

void	free_piece(t_filler *info)
{
	if (info->piece != NULL)
	{
		while (*piece != 0)
		{
			free(*piece);
			piece++;
		}
		free(piece);
	}
}

void	update_data(t_filler *info)
{
	t_point piece;

	/* update map */
	store_map(info->map_size.x, info->map_cur);
	/* update piece */
	free_piece(info);
	store_dim(&(piece.x), &(piece.y), 6);
	store_piece(piece.x, piece.y, info);
	/* update score */
	update_score(info);
}
