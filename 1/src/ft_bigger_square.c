/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigger_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:37:00 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/25 17:57:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_add_dot(char *tetri)
{
	int		i;
	int		count;
	char	tmp[200];

	i = 0;
	count = 0;
	ft_strcpy(tmp, tetri);
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

int 	ft_bigger_square(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetris[i] && sqr_min != 16)
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
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
	return (0);
}
