/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:35 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/21 15:17:23 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void put_error_arr(char **arr)
{
	while (*arr)
	{
		fprintf(stderr, "%s\n", *arr);
		arr++;
	}
}

void	put_error_intarr(int **heatmap, int x, int y)
{
	int i = -1;
	int j;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
			fprintf(stderr, "%d ", heatmap[i][j]);
		fprintf(stderr, "\n");
	}
}

void print_map(t_filler *info)
{
	fprintf(stderr, "MAP DIM = x: %d, y; %d\n", info->map_size.x, info->map_size.y);
	put_error_arr(info->map);
}

void print_piece(t_filler *info)
{
	fprintf(stderr, "PIECE DIM = x: %d, y; %d\n", info->piece.size.x, info->piece.size.y);
	put_error_arr(info->piece.data);
}
/*
void print_coords(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}*/
