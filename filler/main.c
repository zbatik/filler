/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/14 12:52:40 by zbatik           ###   ########.fr       */
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
	ft_putendl("DATA INITALISED");	
//	print_all_info(info);
	place(info);
}
