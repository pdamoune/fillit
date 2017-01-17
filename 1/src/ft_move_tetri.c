/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:31:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 19:04:33 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"


int		ft_move_tetri(char *tetri, int sqr_min)
{
	int		sqr;
	int		i;

	if (tetri[sqr_min - 1] != '.')
		return (0);
	i = 0;
	sqr = ft_sqrt(sqr_min) - 1;
	while (sqr < sqr_min && tetri[sqr] == '.')
		sqr += ft_sqrt(sqr_min);
	ft_memmove(&tetri[1], tetri, sqr_min - 1);
	tetri[0] = '.';
	if (tetri[sqr + 1] != '.')
	{
		while (sqr < sqr_min && tetri[sqr] == '.')
			sqr += ft_sqrt(sqr_min);
		if (tetri[sqr] != '.')
		ft_move_tetri(tetri, sqr_min);
	}
	//ft_putendl(tetri);
	return (1);
}
