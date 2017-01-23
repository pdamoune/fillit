/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:31:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/23 23:40:27 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

int 	ft_can_move(char *tetri, int k, int sqr_min)
{
	int i;

	i = 0;
	if (tetri[sqr_min] != '.')
	{
		return (0);
	}
	if ((tetri[sqr_min - k] != '.'
	|| tetri[sqr_min - (k * 2)] != '.')
	&& (tetri[sqr_min - 1] != '.'
	|| tetri[sqr_min - 2] != '.'))
	{
		return (0);
	}
	// while (i < (int)ft_strlen(tetri))
	// {
	// 	if (i % ft_sqrt(ft_strlen(tetri)) == 0)
	// 		ft_putchar('\n');
	// 	ft_putchar(tetri[i]);
	// 	i++;
	// }
	return (1);
}

int 	ft_move_vertical(char *tetri, char *lst_tetri, int sqr, int sqr_min)
{
	int i;
	int k;


	(void)&lst_tetri;
	(void)&sqr;
	i = 0;
	while (tetri[i] == '.')
		i++;
	k = ft_sqrt(sqr_min);
	k = ((i / k) + 1) * k;
	i = sqr_min;
	// k = ft_sqrt(sqr_min);
	while (i < sqr_min - ft_sqrt(sqr_min) - 1 && tetri[i] == '.')
		i++;
	if (i != sqr_min)
		return(0);
		// ft_putendl(tetri);
	ft_memset(tetri, '.', sqr_min);
	ft_memcpy(&tetri[k], lst_tetri, ft_strlen(lst_tetri));


	return (1);
}

int		ft_move_tetri(char *tetri, char *lst_tetri, char *result, int sqr_min)
{
	int		sqr;
	int		k;
	int		i;
	char	tmp[200];

	(void)&result;
	ft_bzero(tmp, 201);
	i = 0;
	k = ft_sqrt(sqr_min);
	sqr = k - 1;
	if (!ft_can_move(tetri, k, sqr_min - 1))
		return (0);

	while (sqr < sqr_min && tetri[sqr] == '.')
		sqr += k;
	if (sqr - k != sqr_min - 1)
		return (ft_move_vertical(tetri, lst_tetri, sqr, sqr_min));
	ft_memcpy(tmp, tetri, 200);
	ft_memcpy(&tetri[1], tmp, sqr_min - 1);
	tetri[0] = '.';
	return (1);
}
	// ft_putendl(tetri);
		// ft_putendl(tetri);
		// ft_putendl(lst_tetri);
		// ft_putendl(result);
		// ft_putnbr(i), ft_putendl(tetri);
