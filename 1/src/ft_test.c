/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:22:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/16 03:14:43 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void 	ft_reinit(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;

	i = 0;

	while (*lst_tetri[i])
	{
		ft_memset(tetris[i], '.', sqr_min);
		ft_strcpy(tetris[i], lst_tetri[i]);
		*ft_strchr(tetris[i], '\0') = '.';
		i++;
	}
}

void 	ft_test(char **tetris, char **lst_tetri, int sqr_min)
{
	ft_reinit(tetris, lst_tetri, sqr_min);
}
