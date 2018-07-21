/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:19:31 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/21 15:15:09 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define FD	0

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_point
{
	int	x;
	int y;
}				t_point;

typedef struct	s_piece
{
	t_point offset;
	t_point	size;
	char	**data;
}				t_piece;

typedef struct	s_player
{
	int		opp_token;
	char	token;
}				t_player;

typedef	struct	s_limit
{
	int top;
	int bottom;
	int left;
	int right;
}				t_limit;

typedef struct	s_filler
{
	t_player	player;
	t_point		map_size;
	char		**map;
	t_piece		piece;
	int			turn;
	t_limit		limit;
	int			**heatmap;
	t_point		last_play;
}				t_filler;

t_filler		*init_data();

void			put_error_arr(char **arr);
void			put_error_intarr(int **heatmap, int x, int y);

void			print_piece(t_filler *info);
void			print_map(t_filler *info);
//void			print_coords(int x, int y);

void			get_dimension(int *x, int *y, int offset);
void			update_data(t_filler *info);
int				off_top(char **piece, t_point dim);
int				off_bot(char **piece, t_point dim);
int				off_lef(char **piece, t_point dim);
int				off_rig(char **piece, t_point dim);
void			trim_piece(char **piece, t_filler *info);
int				place(t_filler *info, t_point *output);
void			update_limit(t_filler *info);
#endif
