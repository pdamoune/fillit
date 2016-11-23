/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:25:03 by philippe          #+#    #+#             */
/*   Updated: 2016/11/19 21:05:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
