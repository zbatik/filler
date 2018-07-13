/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:09:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 14:31:39 by zbatik           ###   ########.fr       */
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
	place(info);
}
