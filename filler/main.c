/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 13:18:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*info;
	int			ret;

	info = init_data();
	print_player_info(info);
	while (1)
	{
		update_data(info);
		print_map(info);
		print_piece(info);
		ret = place(info);
		if (ret == 0)
		{
			print_coords("", 0, 0);
			break ; 
		}
	}
}
