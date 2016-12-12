/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:36:33 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/24 09:37:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_struct(char **coordonnees, unsigned char name)
{
	t_tetri			*tetri;

	if ((tetri = (t_tetri *)malloc(sizeof(t_tetri))))
	{
		tetri->nom		= name; // A B C D E F
		tetri->y0		= coordonnees[0];
		tetri->y1		= coordonnees[1];
		tetri->y2		= coordonnees[2];
		tetri->y3		= coordonnees[3];

	}
	return (tetri);
}
