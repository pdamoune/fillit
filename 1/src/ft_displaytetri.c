/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaytetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:20:38 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/29 02:30:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_displaytetri(t_list *tetri)
{
	t_list	*tmp;

	tmp = tetri;
	while(tmp->next)
	{
		ft_putchar(((t_tetri *)tmp->content)->nom);
		ft_putendl("");
		ft_putendl(((t_tetri *)tmp->content)->y0);
		ft_putendl(((t_tetri *)tmp->content)->y1);
		ft_putendl(((t_tetri *)tmp->content)->y2);
		ft_putendl(((t_tetri *)tmp->content)->y3);
		ft_putendl("");
		tmp = tmp->next;
	}
}
