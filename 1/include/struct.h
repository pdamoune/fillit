/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:38:35 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/22 16:48:28 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_tetri	t_tetri;
struct		s_tetri
{
	char	nom;
	char	*test;
	char	*origin;
	int		cp1;
	int		cp2;
	int		cp3;
	int		cp4;
};

#endif
