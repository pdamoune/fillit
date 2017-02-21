/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:55:10 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:05:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Checks for white-space characters. These are:
** space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
** horizontal tab ('\t'), and vertical tab ('\v').
*/

int	ft_isspace(int c)
{
	if ((c >= 10 && c <= 13) || ft_isblank(c))
		return (1);
	return (0);
}
