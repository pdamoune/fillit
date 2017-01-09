/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/09 18:46:17 by pdamoune         ###   ########.fr       */
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
void	ft_setup(char *tmp)
{
	while (tmp[0] == '.' && tmp[4] == '.' && tmp[8] == '.'
		&& !ft_isalpha(tmp[12]))
			ft_strcpy(tmp, tmp + 1);
}

int		ft_move_vertical(char *tmp, int sqrt_min)
{
	int		sqr;

	ft_setup(tmp);
	sqr = sqrt_min - 1;
	if (&tmp[sqrt_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr >= sqrt_min - ft_sqrt(sqrt_min))
	{
		if (tmp[sqr] == '.')
			sqr -= 1;
		else
			return (0);
	}
	ft_memmove(&tmp[ft_sqrt(sqrt_min)], tmp, sqr + 1);
	sqr = ft_sqrt(sqrt_min) - 1;
	while (sqr + 1)
		tmp[sqr--] = '.';
	return (1);
}

int		ft_move_horizontal(char *tmp, int sqrt_min)
{
	int		sqr;

	sqr = ft_sqrt(sqrt_min) - 1;
	if (&tmp[sqrt_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr < sqrt_min)
	{
		if (tmp[sqr] == '.')
			sqr += ft_sqrt(sqrt_min);
		else
			return (0);
	}
	ft_memmove(&tmp[1], tmp, sqrt_min - 1);
	tmp[0] = '.';
	return (1);
}

int		ft_test_tetri(char *tmp, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	if (!ft_strdift(result, tmp))
		return (0);
	while (tmp[i])
	{
		if (tmp[i] != '.')
			result[j] = tmp[i];
		i++;
		j++;
	}
	return (1);
}

int		ft_test_combi(char *tmp, char *result, int sqrt_min)
{
	if (ft_test_tetri(tmp, result))
		return (1);
	if (!ft_move_horizontal(tmp, sqrt_min))
		if (!ft_move_vertical(tmp, sqrt_min))
			return (0);
	ft_test_combi(tmp, result, sqrt_min);
	ft_putendl(tmp);
	return (-1);
}

int		ft_solver(char **lst_tetri, int sqrt_min)
{
	char	tmp[sqrt_min + 1];
	char	result[sqrt_min + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(result, sqrt_min + 1);
	ft_memset(result, '.', sqrt_min);
	while (lst_tetri[i][0])
	{
		ft_bzero(tmp, sqrt_min + 1);
		ft_memset(tmp, '.', sqrt_min);
		ft_strcpy(tmp, lst_tetri[i]);
		if (ft_test_combi(tmp, result, sqrt_min) == -1)
		{
			ft_memset(result, '.', sqrt_min + 1);
			ft_move_horizontal(lst_tetri[0], sqrt_min);
			i = -1;
		}
		ft_putendl(result);

		i++;
	}
	return(0);
}
