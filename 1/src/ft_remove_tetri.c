/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:45:30 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/23 08:19:44 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Remove the current *tetri from the string *result.
*/

void	ft_remove_tetri(char *tetri, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetri[j] == '.')
		j++;
	while (result[i] && (result[i] != tetri[j]))
		i++;
	while (result[i])
	{
		if (result[i] == tetri[j])
			result[i] = '.';
		i++;
		j++;
	}
}
