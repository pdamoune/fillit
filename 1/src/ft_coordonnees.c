/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordonnees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:41:55 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/22 16:50:24 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 	ft_coordonnees(char *str, t_tetri test)
{
	int		i;
	int		coord;

	coord = test->cp1;
	i = 0;
	while (str[i])
	{
		if (str[i] != '#')
			i++;

	}
}
