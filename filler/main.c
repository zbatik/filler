/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 16:49:18 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler *info;
	int fd;

	fd = open("../resources/out_put", O_RDONLY);
	info = init_data();
	close(FD);
	ft_putendl("DATA INIT");	
	print_all_info(info);
	place(info);
}
