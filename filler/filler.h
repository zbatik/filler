/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:19:31 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/18 15:19:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define FD	0

# include "../libft/includes/libft.h"
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
	t_point offset;
	t_point	size;
	char	**data;
}					t_piece;

typedef struct		s_player
{
	int		nbr;
	int		opp_token;
	char	token;
}					t_player;

typedef	struct		s_limit
{
	int top;
	int bottom;
	int left;
	int right;
}					t_limit;

typedef struct		s_filler
{
	t_player	player;
	t_point		map_size;
	char		**map;
	t_piece		piece;
	int			turn;
	t_limit		limit;
}					t_filler;

t_filler	*init_data();
void		print_all_info(t_filler *info);
void 		print_score(t_filler *info);
void 		print_player_info(t_filler *info);
void 		print_piece(t_filler *info);
void 		print_map(t_filler *info);
void		print_coords(char *s, int x, int y);
void		print_limit(t_filler *info);

void		get_dimension(int *x, int *y, int offset);
void		store_info(int x, char **store);
void		update_data(t_filler *info);
void		get_score(int *p1, int *p2, t_point size, char **map);
int 		place(t_filler *info);
void		update_limit(t_filler *info);
#endif
