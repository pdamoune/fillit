/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/29 09:19:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_istetri(int fd)
{
	char			str[21];
	char			*tmp;
	int				i;
	// t_tetri			*tetri;
	// int				name_struct;

	// name_struct = 'A';
	i = 0;
	ft_bzero(str, 22);
	while (read(fd, str, 21) > 0)
	{
		i = 0;
		tmp = ft_strdup(str);
		if (!(tmp = ft_is_good(tmp)))
			return (0);
		while (tmp[i++] != '#')
		{
			if (i == 4)
			{
				if (tmp[0] == '.' && tmp[4] == '.' && tmp[8] == '.' && tmp[12] != '#')
					tmp = tmp + 1;
				tmp = &tmp[4];
				i = 0;
			}
		}
		ft_putendl(tmp);
		// ft_putendl(tmp);
		ft_putnbr(i);


		// if (name_struct == 'A')
		// 	tetri = ft_struct(ft_strsplit(tmp, '\n'), name_struct);
		// ft_displaytetri(tetri);
	}
		//tmp = ft_conv_bin(tmp, '#', '.');
	return (0);
}
