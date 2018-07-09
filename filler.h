/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:19:31 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/09 18:41:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"

typedef struct		s_coord
{
	int x;
	int y;
}					coord;

typedef struct		s_filler
{
	coord	map_dim; 
	coord	piece_dim;
	char	**map;
	char	**piece;
}					filler;

#endif
