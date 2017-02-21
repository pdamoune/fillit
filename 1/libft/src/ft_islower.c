/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:20:37 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:05:26 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Checks for a lower-case character.
*/

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
