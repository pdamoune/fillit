/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 16:57:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void	ft_fillit(char *argv)
{
	int		fd;
	int		sqrt_min;
	char	*lst_tetri[27];
	char	*tetris[27];

	// char	*tetri;

	ft_bzero(lst_tetri, 28);
	ft_bzero(tetris, 28);
	fd = open(argv, O_RDONLY);
    if (fd == -1)
		ft_putendl("error");
	if ((sqrt_min = ft_is_tetri(fd, tetris, lst_tetri)) == 0)
		ft_putendl("error");
	else
	{
		sqrt_min *= sqrt_min;
		if (!ft_strcmp(lst_tetri[0], "AA..AA") && sqrt_min == 4)
			ft_strcpy(tetris[0], "AAAA");
		else if(sqrt_min == 4)
			sqrt_min = 9;
		ft_solver(tetris, lst_tetri, sqrt_min);
	}
	// printf("grille : %d\n\n", sqrt_min);
	close(fd);

}
