/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/18 02:35:08 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

int		ft_test_combi(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	static int i = 0;

	while (tetris[i])
	{
		// ft_putendl(result);
		//ft_putnbr(sqr_min), ft_putchar('='), ft_putendl(result);
		if (i == -1)
			return (0);
		if (ft_test_tetri(tetris[i], result) == 1)
		{
			i++;
		}
		else if (ft_move_tetri(tetris[i], lst_tetri[i], sqr_min) != 0)
		{
			ft_test_combi(tetris, lst_tetri, result, sqr_min);
		}
		else
		{
			ft_remove_tetri(tetris[--i], result);
			if (ft_move_tetri(tetris[i], lst_tetri[i], sqr_min) == 0)
			{
				if (i == 0)
				{
					// ft_putnbr(sqr_min), ft_putendl(result);
					sqr_min = (ft_sqrt(sqr_min) + 1) * (ft_sqrt(sqr_min) + 1);
					// ft_putendl(lst_tetri[0]);
					ft_test(tetris, lst_tetri, sqr_min);
					// ft_putendl(tetris[1]);
					ft_bigger_square(tetris, lst_tetri, result, sqr_min);
					ft_test_combi(tetris, lst_tetri, result, sqr_min);
				}
				else
				{
					ft_test(&tetris[i], &lst_tetri[i], sqr_min);
					ft_remove_tetri(tetris[--i], result);
					ft_move_tetri(tetris[i], lst_tetri[i], sqr_min);
					ft_test_combi(tetris, lst_tetri, result, sqr_min);
				}
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
	i = 0;
	ft_putendl("");
	printf("grille = %d\n\n", sqr_min);

	while (lst_tetri[i])
		printf("lst original    = %s\n", lst_tetri[i++]);
	i = 0;
	while (tetris[i])
	{
		printf("tetri original  = %s = %lu\n", tetris[i], ft_strlen(tetris[i]));
		i++;
	}
	printf("result original = %s = %lu\n", result, ft_strlen(result));
	ft_putendl("");

	ft_set_square(tetris, lst_tetri, result, sqr_min);

	// ft_test_combi(tetris, lst_tetri, result, sqr_min);
	i = 0;
	// while (i++ < 30)
	// 	ft_move_tetri(tetris[9], lst_tetri[9], sqr_min);




	i = 0;
	ft_putendl("");
	i = 0;
	while (lst_tetri[i])
		printf("lst modifie    = %s\n", lst_tetri[i++]);
	i = 0;
	while (tetris[i])
	{
		printf("tetri modifie  = %s = %lu\n", tetris[i], ft_strlen(tetris[i]));
		i++;
	}
	result[199] = 0;
	printf("result modifie = %s = %lu\n", result, ft_strlen(result));
	i = 0;
	// while (lst_tetri[j])
	// {
	// 	while (i < (int)ft_strlen(tetris[j]))
	// 	{
	// 		if (i % ft_sqrt(ft_strlen(result)) == 0)
	// 			ft_putchar('\n');
	// 		ft_putchar(tetris[j][i]);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	ft_putendl("");
	// 	j++;
	// }
	ft_putendl("");
	i = 0;
	ft_putendl("=== result ===");
	while (i < (int)ft_strlen(result))
	{
		if (i % ft_sqrt(ft_strlen(result)) == 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	return(0);
}
