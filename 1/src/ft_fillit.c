/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2016/12/31 15:24:23 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
	sqrt_min = ft_istetri(fd, lst_tetri);
	close(fd);
	sqrt_min *= sqrt_min;

	ft_putendl(""), ft_putnbr(ft_solver(lst_tetri, sqrt_min));

	// ft_move_tetri(tetri);
	// if (tetri != NULL)
	// 	ft_displaytetri(tetri);
	ft_putendl("");

}
