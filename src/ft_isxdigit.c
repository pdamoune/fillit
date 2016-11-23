/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:50:02 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/19 23:33:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks for a hexadecimal digits, that is, one of
** 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F.
*/

int		ft_isxdigit(int c)
{
	if (ft_isdigit(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return (1);
	return (0);
}
