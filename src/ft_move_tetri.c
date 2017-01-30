/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:31:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 12:16:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

int		ft_can_move(char *tetri, int k, int sqr_min)
{
	int i;

	i = 0;
	if (tetri[sqr_min] != '.')
		return (0);
	if ((tetri[sqr_min - k] != '.'
	|| tetri[sqr_min - (k * 2)] != '.')
	&& (tetri[sqr_min - 1] != '.'
	|| tetri[sqr_min - 2] != '.'))
		return (0);
	return (1);
}

int		ft_move_vertical(char *tetri, char *lst_tetri, int sqr_min)
{
	int i;
	int k;

	i = 0;
	while (tetri[i] == '.')
		i++;
	k = ft_sqrt(sqr_min);
	k = ((i / k) + 1) * k;
	i = sqr_min;
	while (i < sqr_min - ft_sqrt(sqr_min) - 1 && tetri[i] == '.')
		i++;
	if (i != sqr_min)
		return (0);
	ft_memset(tetri, '.', sqr_min);
	ft_memcpy(&tetri[k], lst_tetri, ft_strlen(lst_tetri));
	if (sqr_min == 9)
		ft_rem_dot(tetri, sqr_min);
	return (1);
}

int		ft_move(char *tetri, char *lst_tetri, int sqr_min)
{
	int		sqr;
	int		k;
	int		i;
	char	tmp[200];

	ft_bzero(tmp, 201);
	i = 0;
	k = ft_sqrt(sqr_min);
	sqr = k - 1;
	if (!ft_can_move(tetri, k, sqr_min - 1))
		return (0);
	while (sqr < sqr_min && tetri[sqr] == '.')
		sqr += k;
	if (sqr - k != sqr_min - 1)
		return (ft_move_vertical(tetri, lst_tetri, sqr_min));
	ft_memcpy(tmp, tetri, 200);
	ft_memcpy(&tetri[1], tmp, sqr_min - 1);
	tetri[0] = '.';
	return (1);
}
