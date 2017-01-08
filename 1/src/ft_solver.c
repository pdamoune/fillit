/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/04 13:55:36 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

// void 	ft_move_tetri(char *tetri, int sqrt_min)
// {
	/*

	ft_memmove(&tetri[1], &tetri[0], sqrt_min - 1);
	tetri[0] = '.';
	if (tetri[sqrt_min - 1] != '\0')
 		ft_putendl(tetri);

	*/

// }
int		ft_move_tetri(char *tmp)
{
	ft_memmove(&tmp[1], tmp, 24);
	if (ft_count_occur(tmp, !ft_strchr(tmp, '.')))
		ft_putendl(tmp);
	tmp[0] = '.';
	return (1);
}

int		ft_test_tetri(char *tmp, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!ft_strdift(&result[j], tmp))
		j++;
	if (ft_strlen(tmp) + j > ft_strlen(result))
		return (0);
	if (ft_strdift(&result[j], tmp))
		while (tmp[i])
		{
			if (tmp[i] != '.')
				result[j] = tmp[i];
			i++;
			j++;
		}
	return (1);
}

int		ft_solver(char **lst_tetri, int sqrt_min)
{
	char	tmp[sqrt_min + 1];
	char	result[sqrt_min + 1];
	int		i;

	i = 0;
	ft_bzero(tmp, sqrt_min + 1);
	ft_bzero(result, sqrt_min + 1);
	ft_memset(result, '.', sqrt_min);
	while (lst_tetri[i][0])
	{
		ft_strcpy(tmp, lst_tetri[i]);
		while (!ft_test_tetri(tmp, result))
		{
			if ((int)ft_strlen(tmp) == sqrt_min)
				{
					i--;
					ft_clear_tetri(result, i);
					ft_strcpy(tmp, lst_tetri[i]);
					ft_move_tetri(tmp);

				}
			ft_move_tetri(tmp);
			ft_putendl(tmp);
		}
		i++;
		// ft_putendl(tmp);
		// ft_putendl(result);
	}
	return(0);
}
