/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:22:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 16:56:06 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void 	ft_reinit_low(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;
	char	tmp[17];

	i = 0;
	while (tetris[i])
	{
		if (tetris[i][0] == '.' && tetris[i][1] == '.' && tetris[i][2] == '.' )
		{
			ft_strcpy(tmp, tetris[i]);
		}

		ft_memset(tetris[i], '.', sqr_min);
		ft_strcpy(tetris[i], lst_tetri[i]);
		*ft_strchr(tetris[i], '\0') = '.';
		tetris[i][sqr_min] = 0;
		i++;
	}
}

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

void 	ft_test(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	(void)&result;
	if (sqr_min == 9)
		ft_reinit_low(tetris, lst_tetri, sqr_min);
	else
		ft_reinit(tetris, lst_tetri, sqr_min);
}
