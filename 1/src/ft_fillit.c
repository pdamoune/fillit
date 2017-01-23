/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 00:48:53 by pdamoune         ###   ########.fr       */
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
		exit(1);
	if ((sqrt_min = ft_is_tetri(fd, tetris, lst_tetri)) == 0)
		ft_putendl("error");
	else
{
	sqrt_min *= sqrt_min;
	if (sqrt_min < 16)
		sqrt_min = 16;
	ft_solver(tetris, lst_tetri, sqrt_min);
}
	// printf("grille : %d\n\n", sqrt_min);
	close(fd);

}
