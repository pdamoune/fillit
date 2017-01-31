/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/31 22:18:24 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_tabdel(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
}

void	ft_fillit(char *argv)
{
	int		fd;
	int		sqr_min;
	char	*lst_tetri[27];
	char	*tetris[27];
	char	result[200];

	ft_bzero(lst_tetri, 216);
	ft_bzero(tetris, 216);
	ft_bzero(result, 200);
	ft_memset(result, '.', 196);
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_putendl("error");
	else if ((sqr_min = ft_is_tetri(fd, tetris, lst_tetri)) == 0)
		ft_putendl("error");
	else
		ft_solver(tetris, lst_tetri, result, sqr_min * sqr_min);
	ft_tabdel(lst_tetri);
	ft_tabdel(tetris);
	close(fd);
}
