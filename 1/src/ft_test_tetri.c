/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:58:23 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 00:31:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Test if the tetri *tmp fit int the string *result.
*/

int		ft_test_tetri(char *tmp, char *result, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (tmp[i] != c)
		i++;
	while (tmp[i])
	{
		if (tmp[i] == c && result[i] == '.')
		{
			result[i] = tmp[i];
			j++;
		}
		i++;
	}
	if (j == 4)
		return (1);
	while (j > 0)
	{
		if (result[i] == c)
		{
			result[i] = '.';
			j--;
		}
		i--;
	}
	return (0);
}
