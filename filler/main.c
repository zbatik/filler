/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/20 15:51:47 by zbatik           ###   ########.fr       */
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

	output.x = 0;
	output.y = 0;
	info = init_data();
	while (1)
	{
		update_data(info);
		success = place(info, &output);
		print_coords(output);
		if (success == 0)
			break ;
	}
	ft_arrdel(&info->piece.data, info->piece.size.x);
	ft_arrdel(&info->map, info->map_size.x);
	free(info);
}
