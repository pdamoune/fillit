/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:38:35 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/29 02:32:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "fillit.h"

typedef struct s_tetri	t_tetri;
struct		s_tetri
{
	char	nom;
	char	*y0;
	char	*y1;
	char	*y2;
	char	*y3;
};

t_tetri		*ft_struct(char **coordonnes, unsigned char name);
void		ft_displaytetri(t_list *tetri);
// void 		ft_move_block(char *y0, char *y1, char *y2, char *y3);
// void		ft_move_tetri(t_list *tetri);

#endif
