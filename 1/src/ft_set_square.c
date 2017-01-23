/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:52:02 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/19 06:17:00 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Modify all the tetris from **tetris and **lst_tetri, to fit in a
** sqr_min square.
*/

void 	ft_set_square(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;

	i = 4;
	while ((int)ft_strlen(tetris[0]) != sqr_min)
	{
		ft_bigger_square(tetris, lst_tetri, result, (i + 1) * (i + 1));
		i++;
	}
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
}
