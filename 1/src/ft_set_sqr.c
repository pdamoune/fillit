/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sqr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:52:02 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 11:28:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_set_sqr(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int	i;

	i = 4;
	while ((int)ft_strlen(tetris[0]) < sqr_min && sqr_min != 4)
	{
		ft_big_sqr(tetris, lst_tetri, result, (i + 1) * (i + 1));
		i++;
	}
	if (sqr_min == 9)
		if (!ft_low_sqr(tetris, result, sqr_min))
		{
			ft_memset(result, '.', 16);
			result[16] = 0;
			return (16);
		}
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
	return (sqr_min);
}
