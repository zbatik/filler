/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:20:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 12:13:14 by zbatik           ###   ########.fr       */
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
/*
void	store_piece(int x, int y, t_filler info)
{
	int		i;
	char	*in;
	char	tmp[x][y];

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
*/
/*
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
	int cp = 0;
	while (cp < x - (offset[0] + offset[1]))
	{
		info->piece.cur[cp] = ft_strdup(piece[cp + offset[0]]};
		cp++;
	}
	info->piece.cur[cp] = 0;
}
*/
void	get_dimension(int *x, int *y, int offset)
{
	char	*line;
	int		ret;
//	int		cmp;

	ret = get_next_line(FD, &line);
/*	if (offset == 8)
		cmp = 1 == ft_strncmp("Plateau ", line, offset);
	else
		cmp = 1 == ft_strncmp("Piece ", line, offset);
	if (cmp == 0 || ret < 1)
		perror("not reading the dimension line");
*/
	*x = ft_atoi(line + offset);
	*y = ft_atoi(line + ft_strlen(ft_itoa(*x)) + offset);
	free(line);
}

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

static void	free_piece(char **piece)
{
	if (piece != NULL)
	{
		while (*piece != 0)
		{
			free(*piece);
			piece++;
		}
		// free(piece); // probably null
	}
}

void	update_data(t_filler *info)
{
	get_info(info->map_size.x, 4, info->map);
	/* update piece */
	free_piece(info->piece.data);
	get_dimension(&(info->piece.x), &(info->piece.y), 6);
	info->piece.data = ft_arrnew(info->piece.x, info->piece.y);
	get_info(info->piece.x, 0,  info->piece.data);
	/* update score */
	get_score(&(info->p1_score), &(info->p2_score), info->map_size, info->map);
}
