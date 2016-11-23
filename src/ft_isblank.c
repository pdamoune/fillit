/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:31:21 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/08 18:43:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks for a blank character; that is, a space or a tab.
*/

int	ft_isblank(int c)
{
	if (c == 9 || c == 32)
		return (1);
	return (0);
}
