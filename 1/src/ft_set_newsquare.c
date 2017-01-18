/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_newsquare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:38:51 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/18 02:47:42 by pdamoune         ###   ########.fr       */
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

	i = ft_sqrt(sqr_min);
	ft_bigger_square(tetris, lst_tetri, result, (i + 1) * (i + 1));

}
