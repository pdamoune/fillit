/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:31:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/18 02:25:44 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"


int		ft_move_tetri(char *tetri, char *lst_tetri, int sqr_min)
{
	int		sqr;
	int		i;


	i = 0;
	sqr = ft_sqrt(sqr_min) - 1;
	while (sqr < sqr_min && tetri[sqr] == '.')
		sqr += ft_sqrt(sqr_min);
	// ft_putendl(tetri);
	if (ft_count_occur(tetri, '.') != sqr_min - 4
	|| ((tetri[sqr_min - ft_sqrt(sqr_min) - 1] != '.'
	|| tetri[sqr_min - (ft_sqrt(sqr_min) * 2) - 1] != '.')
	&& (tetri[sqr_min - 3] != '.'
	|| tetri[sqr_min - 2] != '.'
	|| tetri[sqr_min - 1] != '.')))
		return (0);
	ft_memmove(&tetri[1], tetri, sqr_min - 1);
	tetri[0] = '.';
	if (tetri[sqr + 1] != '.')
	{
		while (sqr < sqr_min && tetri[sqr] == '.')
			sqr += ft_sqrt(sqr_min);
		if (tetri[sqr] != '.')
			ft_move_tetri(tetri, lst_tetri, sqr_min);
	}
	// ft_putendl(tetri);
		// ft_putendl(tetri);
		// ft_putendl(lst_tetri);
	return (1);
}
