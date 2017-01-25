/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:33:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/25 18:34:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void 	ft_rem_dot(char *tetri, int sqr_min)
{
	int		i;
	int		count;
	char	tmp[200];

	i = 0;
	count = 0;
	ft_strcpy(tmp, tetri);
	while (tmp[i])
	{
		while (tmp[i] == '.')
			i++;
		while (ft_isalpha(tmp[i]) && count < 4)
		{
			i++;
			count++;
		}
		if (count == 4)
			break;
		ft_strcpy(&tetri[i], &tmp[i + 1]);
		ft_strcpy(tmp, tetri);
	}
	*ft_strchr(tetri, 0) = '.';
	tetri[sqr_min] = 0;
}
