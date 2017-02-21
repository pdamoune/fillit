/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:14:20 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:34 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Assigne la valeur ’\0’ à tous les caractères de la chaine passée
** en paramètre.
*/

void	ft_strclr(char *str)
{
	if (str)
		ft_bzero(str, ft_strlen(str));
}
