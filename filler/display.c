/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:35 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/23 14:25:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	print_coords(t_point output)
{
	ft_putnbr(output.x);
	ft_putchar(' ');
	ft_putnbr(output.y);
	ft_putchar('\n');
}
