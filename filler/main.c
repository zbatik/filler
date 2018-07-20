/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/20 16:38:01 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(t_point output)
{
	ft_putnbr(output.x);
	ft_putchar(' ');
	ft_putnbr(output.y);
	ft_putchar('\n');
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
		print_coords(output);
		info->last_play = output;
		if (success == 0)
			break ;
	}
	ft_arrdel(&info->piece.data, info->piece.size.x);
	ft_arrdel(&info->map, info->map_size.x);
	free(info);
}
