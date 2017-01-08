/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2016/12/29 14:55:41 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

int 	ft_istetri(int fd, char **lst_tetri)
{
	char			buf[21];
	int				letter;

	letter = 'A';
	ft_bzero(buf, 22);
	ft_bzero(lst_tetri, 26);
	while (read(fd, buf, 21) > 0)
	{
		if (!ft_parsing(buf))
			return (0);
		while (buf[0] == '.' && buf[4] == '.' && buf[8] == '.'
			&& buf[12] != '#')
				ft_strcpy(buf, buf + 1);
		while (buf[0] == '.' && buf[1] == '.' && buf[2] == '.'
			&& buf[3] == '.')
				ft_strcpy(buf, &buf[4]);
		*(ft_strrchr(buf, '#') + 1) = 0;
		while (ft_strchr(buf, '#'))
			*ft_strchr(buf, '#') = letter;
		lst_tetri[letter - 65] = ft_strdup(buf);
		ft_bzero(buf, 22);
		letter++;
	}
	lst_tetri[letter - 65] = ft_strdup(buf);

	return (ft_sqrt_min((letter - 65) * 4));
}
