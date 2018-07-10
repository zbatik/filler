/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:19:31 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/10 17:23:03 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYER_NAME "zbatik.filler"
# define FD	3
# define P1_TOKEN 'O'
# define P2_TOKEN 'X'
# define BLANK '.'

# include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


typedef struct		s_point
{
	int	x;
	int y;
}					t_point;

typedef struct		s_piece
{
	int		x;
	int		y;
	char	**cur;
}					t_piece;

typedef struct		s_player
{
	int		nbr;
	char	token;
	t_point	start;
}					t_player;

typedef struct		s_filler
{
	t_player	player;
	t_point		map_size;
	char		**map_cur;
	t_piece		piece;
	int			turn;
	int			p1_score;
	int			p2_score;
}					t_filler;

void	print_all_info(t_filler *info);

#endif
