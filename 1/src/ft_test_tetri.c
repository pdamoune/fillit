/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:58:23 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 19:02:22 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Test if the tetri *tmp fit int the string *result.
*/

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
