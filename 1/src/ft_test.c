/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:22:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 10:40:56 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void 	ft_reinit(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;

	i = 0;

	while (lst_tetri[i])
	{
		ft_memset(tetris[i], '.', sqr_min);
		ft_strcpy(tetris[i], lst_tetri[i]);
		*ft_strchr(tetris[i], '\0') = '.';
		tetris[i][sqr_min] = 0;
		i++;
	}
}

int		ft_test(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	(void)&result;
	if (sqr_min == 9)
	{
		ft_reinit(tetris, lst_tetri, 16);
		ft_lower_square(tetris, result, sqr_min);
	}
	else
		ft_reinit(tetris, lst_tetri, sqr_min);
	return (0);
}
