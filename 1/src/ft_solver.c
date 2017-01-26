/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/26 10:57:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_combi(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int		i;
	int		k;

	i = ft_test(tetris, lst_tetri, result, sqr_min);
	k = 1;
	while (tetris[i] && lst_tetri[i])
	{
		if (k && ft_test_tetri(tetris[i], result, i + 65))
			i++;
		else if (!(k = ft_move(tetris[i], lst_tetri[i], sqr_min)))
		{
			ft_test(&tetris[i], &lst_tetri[i], result, sqr_min);
			ft_remove_tetri(tetris[--i], result);
			if (!(k = ft_move(tetris[i], lst_tetri[i], sqr_min)) && i == 0)
			{
				sqr_min = ft_sqrt(sqr_min) + 1;
				sqr_min *= sqr_min;
				ft_test(tetris, lst_tetri, result, sqr_min);
				k = ft_big_sqr(tetris, lst_tetri, result, sqr_min);
			}
		}
	}
	return (1);
}

int		ft_solver(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strcmp(lst_tetri[0], "AA..AA") && sqr_min == 4)
		ft_strcpy(tetris[0], "AAAA");
	else if (sqr_min == 4)
		sqr_min = 9;
	if ((sqr_min = ft_set_sqr(tetris, lst_tetri, result, sqr_min)) == 16)
		ft_test(tetris, lst_tetri, result, sqr_min);
	ft_combi(tetris, lst_tetri, result, sqr_min);
	while (i < (int)ft_strlen(result))
	{
		if (i % ft_sqrt(ft_strlen(result)) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	return (0);
}
