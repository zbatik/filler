/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/20 15:32:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*info;
	int			ret;

	info = init_data();
	while (1)
	{
		update_data(info);
		ret = place(info);
		if (ret == 0)
		{
			print_coords(0, 0);
			break ;
		}
	}
	ft_arrdel(&info->piece.data, info->piece.size.x);
	ft_arrdel(&info->map, info->map_size.x);
	free(info);
}
