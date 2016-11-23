/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:29:19 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/15 11:56:51 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prend en paramètre l’adresse d’une chaine de caractères qui
** doit être libérée avec free(3) et son pointeur mis à NULL.
*/

void	ft_strdel(char **str)
{
	ft_memdel((void **)str);
}
