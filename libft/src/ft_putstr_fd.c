/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:25:26 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/20 04:50:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ecrit la chaine str sur le descripteur de fichier fd.
*/

void	ft_putstr_fd(char const *str, int fd)
{
	if (str)
		while (*str)
			ft_putchar_fd(*str++, fd);
}
