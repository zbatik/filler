/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:35 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 10:33:48 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(t_filler *info)
{
	ft_putendl("CURRENT MAP");
	ft_putstr("\tMAP x: ");
	ft_putnbr(info->map_size.x);
	ft_putchar('\n');
	ft_putstr("\tMAP y: ");
	ft_putnbr(info->map_size.y);
	ft_putchar('\n');
	ft_putstrarr(info->map);
}

void print_piece(t_filler *info)
{
	ft_putendl("CURRENT PEICE");
	ft_putstr("\tPIECE x: ");
	ft_putnbr(info->piece.x);
	ft_putchar('\n');
	ft_putstr("\tPIECE y: ");
	ft_putnbr(info->piece.y);
	ft_putchar('\n');
	ft_putstrarr(info->piece.data);
}

void print_player_info(t_filler *info)
{	
	ft_putendl("PLAYER INFO:");
	ft_putstr("YOU ARE: ");
	ft_putstr(PLAYER_NAME);
	ft_putstr(" PLAYING AS PLAYER ");
	ft_putnbr(info->player.nbr);
	ft_putstr(" WITH ");
	ft_putchar(info->player.token);
	ft_putchar('\n');
}

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

void	print_all_info(t_filler *info)
{
	print_player_info(info);	
	print_map(info);
	print_piece(info);
	print_score(info);
	ft_putstr("CURRENT TURN: "); 
	ft_putnbr(info->turn);
 	ft_putchar('\n');
}
