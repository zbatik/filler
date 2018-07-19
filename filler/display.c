/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:35 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/19 11:50:14 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void put_error_arr(char ** arr)
{
	while (*arr)
	{
		fprintf(stderr, "%s\n", *arr);
		arr++;
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
void print_player_info(t_filler *info)
{	
	fprintf(stderr, "Playing as Player %d\n with token %c against token %c\n", info->player.nbr, info->player.token, info->player.opp_token);
}
*/
/*
void print_score(t_filler *info)
{
	ft_putendl("CURRENT SOCORE:");
	ft_putstr("\tP1: ");
	ft_putnbr(info->p1_score);
	ft_putchar('\n');
	ft_putstr("\tP2: ");
	ft_putnbr(info->p2_score);
	ft_putchar('\n');
}
*/

void print_limit(t_filler *info)
{
	ft_putstr("TOP: ");
	ft_putnbr(info->limit.top);
}

void print_coords(char *s, int x, int y)
{
	ft_putstr(s);
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}
void	print_all_info(t_filler *info)
{
//	print_player_info(info);	
	print_map(info);
	print_piece(info);
//	print_score(info);
	ft_putstr("CURRENT TURN: "); 
	ft_putnbr(info->turn);
 	ft_putchar('\n');
}
