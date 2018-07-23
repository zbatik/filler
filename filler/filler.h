/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:19:31 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 13:59:03 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define FD	0
# define DEFUALT_ALGO "dimond"

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

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
	char		*algo;
}				t_filler;

t_filler		*init_data();

void			print_coords(t_point output);

void			set_output(int i, int j, t_point *output, t_filler *info);
void			update_heatmap(t_filler *info);
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
