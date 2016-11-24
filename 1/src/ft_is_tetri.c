/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/24 10:10:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_istetri(int fd)
{
	char			str[21];
	char			*tmp;
	t_list			*tetri;
	int				name_struct;

	name_struct = 'A';
	ft_bzero(str, 22);
	while (read(fd, str, 21) > 0)
	{
		tmp = ft_strdup(str);
		if (!ft_is_good(tmp))
			return (0);
		ft_conv_bin(tmp, '#', '.');
		if (name_struct == 'A')
			tetri = ft_lstnew(ft_struct(ft_strsplit(tmp, '\n'),
			name_struct), sizeof(t_tetri));
		else
			ft_lstprev(tetri, ft_lstnew(ft_struct(ft_strsplit(tmp, '\n'),
			name_struct), sizeof(t_tetri)));
		name_struct++;
	}
		//tmp = ft_conv_bin(tmp, '#', '.');
	return (tetri);
}
