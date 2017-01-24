/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:58:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 17:12:34 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_lower_square(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
	return (0);
