/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:16:41 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/14 13:17:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
