/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:45:30 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 08:51:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Remove the current *tetri from the string *result.
*/

void	ft_remove_tetri(char *tetri, char *result)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (result[i] == tetri[i])
			result[i] = '.';
		i++;
	}
}
