/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_sqr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:58:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 11:27:26 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	ft_can_low(char *tetri, int sqr_min)
{
	int i;

	i = 15;
	while (!ft_isalpha(tetri[i]))
		i--;
	if (i > sqr_min)
		return (0);
	i = 0;
	ft_rem_dot(tetri, sqr_min);
	return (1);
}

int 	ft_low_sqr(char **tetris, char *result, int sqr_min)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetris[i] && sqr_min != 16)
	{
		while (tetris[i][j] == '.')
			j++;
		if (!ft_can_low(&tetris[i][j], sqr_min))
			return (0);
		*ft_strchr(tetris[i], 0) = '.';
		tetris[i][sqr_min] = 0;
		i++;
		j = 0;
	}
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
	return (1);
}
