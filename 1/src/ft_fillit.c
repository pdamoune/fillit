/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/09 15:36:50 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void	ft_fillit(char *argv)
{
	int		fd;
	int		sqrt_min;
	char	*lst_tetri[25];

	// char	*tetri;

	ft_bzero(lst_tetri, 26);
	fd = open(argv, O_RDONLY);
    if (fd == -1)
		exit(1);
	if ((sqrt_min = ft_is_tetri(fd, lst_tetri)) == 0)
		ft_putendl("grille mauvaise");
	sqrt_min *= sqrt_min;
	printf("grille : %d\n\n", sqrt_min);
	ft_solver(lst_tetri, sqrt_min);
	close(fd);

}
