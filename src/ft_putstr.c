/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:49:56 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/20 04:50:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaine str sur la sortie standard.
*/

void	ft_putstr(char const *str)
{
	if (str)
		while (*str)
			ft_putchar(*str++);
}
