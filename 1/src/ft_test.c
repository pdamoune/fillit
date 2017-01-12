/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:22:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/12 02:50:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void 	ft_reinit(char **tetris, char **lst_tetri)
{
	int i;

	i = 0;
	while (*lst_tetri[i])
	{
		ft_memset(tetris[i], '.', 16);
		ft_strcpy(tetris[i], lst_tetri[i]);
		*ft_strchr(tetris[i], '\0') = '.';
		i++;
	}
}

void 	ft_test(char **tetris, char **lst_tetri)
{
	ft_reinit(tetris, lst_tetri);
}
