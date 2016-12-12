/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:13:53 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/24 10:46:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 	ft_move_tetri(t_list *tetri)
{
	ft_move_block(((t_tetri *)tetri->content)->y0, ((t_tetri *)tetri->content)->y1,
	((t_tetri *)tetri->content)->y2, ((t_tetri *)tetri->content)->y3);

}
