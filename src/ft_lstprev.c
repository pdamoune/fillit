/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:39:22 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/21 12:39:27 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute l’élément new en a la suite de alst.
*/

void	ft_lstprev(t_list **alst, t_list *new)
{
	if (!(alst && new))
		return ;
	alst->next = *new
	*new = alst;
}
