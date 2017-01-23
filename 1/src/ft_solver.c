/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/24 00:48:11 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

int		ft_test_combi(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	static int i = 0;
	int k;

	k = 1;
	while (tetris[i] && lst_tetri[i])
	{
		// ft_putendl(result);
		if (k && ft_test_tetri(tetris[i], result, i + 65))
		{
			// ft_putendl(result);
			i++;
		}
		else if (!(k = ft_move_tetri(tetris[i], lst_tetri[i], result, sqr_min)))
		{
			ft_test(&tetris[i], &lst_tetri[i], result, sqr_min);
			ft_remove_tetri(tetris[--i],result);
			if (!(k = ft_move_tetri(tetris[i], lst_tetri[i], result, sqr_min)) && i == 0)
			{
				sqr_min = ft_sqrt(sqr_min) + 1;
				sqr_min *= sqr_min;
				ft_test(tetris, lst_tetri, result, sqr_min);
				ft_bigger_square(tetris, lst_tetri, result, sqr_min);
				k = 1;
			}
		}
	}
	return (1);
}

int		ft_solver(char **tetris, char **lst_tetri, int sqr_min)
{
	char	result[200];
	int		i;
	int		j;

	i = 0;
	j = 0;
	// system("clear");
	ft_bzero(result, 197);
	ft_memset(result, '.', 196);
	ft_set_square(tetris, lst_tetri, result, sqr_min);
	ft_test_combi(tetris, lst_tetri, result, sqr_min);
	while (i < (int)ft_strlen(result))
	{
		if (i % ft_sqrt(ft_strlen(result)) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	return(0);
}
