/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:52:02 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 19:58:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Modify all the tetris from **tetris and **lst_tetri, to fit in a
** sqr_min square.
*/

void	ft_add_dot(char *tetri)
{
	int		i;
	int		count;
	char	tmp[200];

	ft_memset(tmp, '.', 200);
	ft_strcpy(tmp, tetri);
	i = 0;
	count = 0;
	while (tmp[i])
	{
		while (ft_isalpha(tmp[i]) && count < 4)
		{
			i++;
			count++;
		}
		if (count == 4)
			break;
		ft_strcpy(&tetri[i + 1], &tmp[i]);
		tetri[i] = '.';
		ft_strcpy(tmp, tetri);
		while (tmp[i] == '.')
			i++;
	}
}

int 	ft_bigger_square(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ft_sqrt(ft_strlen(tetris[0]));
	lst_tetri[sqr_min] = 0;
	// ft_putnbr(k);
	// ft_putnbr(sqr_min);
	// ft_putendl(tetris[0]);
	ft_putnbr(k);
	ft_putendl("");
	ft_putnbr(sqr_min);
	ft_putendl("");
	while (tetris[i])
	{
		while (tetris[i][j] == '.')
			j++;
		ft_add_dot(&tetris[i][j]);
		*ft_strchr(tetris[i], 0) = '.';
		tetris[i][sqr_min] = 0;
		ft_strcpy(lst_tetri[i], tetris[i]);
		*(ft_strrchr(lst_tetri[i], i + 65) + 1) = 0;
		i++;
		j = 0;
	}

	return (0);
}

void 	ft_set_square(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;

	i = 4;
	while (ft_sqrt(sqr_min) > i)
	{
		ft_bigger_square(tetris, lst_tetri, (i + 1) * (i + 1));
		i++;
	}
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
}
