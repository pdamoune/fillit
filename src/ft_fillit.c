/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 10:38:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

void	ft_fillit(char *argv)
{
	int		fd;
	int		sqr_min;
	char	*lst_tetri[27];
	char	*tetris[27];
	char	result[200];

	ft_bzero(lst_tetri, 28);
	ft_bzero(tetris, 28);
	ft_bzero(result, 201);
	ft_memset(result, '.', 196);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_putendl("error");
	if ((sqr_min = ft_is_tetri(fd, tetris, lst_tetri)) == 0)
		ft_putendl("error");
	else
		ft_solver(tetris, lst_tetri, result, sqr_min * sqr_min);
	close(fd);
}