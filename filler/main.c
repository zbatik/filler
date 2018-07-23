/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 11:58:49 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_output(int i, int j, t_point *output, t_filler *info)
{
	output->x = i - info->piece.offset.x;
	output->y = j - info->piece.offset.y;
}

int		main(void)
{
	t_filler	*info;
	t_point		output;
	int			success;

	info = init_data();
	while (1)
	{
		output = info->last_play;
		update_data(info);
		success = place(info, &output);
		info->last_play = output;
		if (success == 1)
			print_coords(output);
		else
			break ;
	}
	output.x = 0;
	output.y = 0;
	print_coords(output);
	ft_arrdel(&info->piece.data, info->piece.size.x);
	ft_arrdel(&info->map, info->map_size.x);
	free(info);
}
