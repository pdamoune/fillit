/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/24 14:06:26 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

char 	*ft_set_tetris(char *buf)
{
	char *tetri;

	tetri = ft_strnew(200);
	ft_bzero(tetri, 201);
	ft_memset(tetri, '.', 200);
	ft_strcpy(tetri, buf);
	*ft_strchr(buf, '\0') = '.';
	return (tetri);
}

int 	ft_is_tetri(int fd, char **tetris, char **lst_tetri)
{
	char			buf[21];
	int				next;
	int				letter;

	letter = 'A';
	ft_bzero(buf, 22);
	while (read(fd, buf, 21) > 0)
	{
		buf[20] == '\n' ? next = 1 : 0;
		ft_strlen(buf) == 20 ? next = 0 : 1;
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
		tetris[letter - 65] = ft_set_tetris(buf);
		*ft_strchr(tetris[letter - 65], '\0') = '.';
		tetris[letter - 65][16] = 0;
		lst_tetri[letter - 65] = ft_set_tetris(buf);
		*(ft_strrchr(lst_tetri[letter - 65], letter) + 1) = 0;
		letter++;
	}
	if (next == 0)
		return (ft_sqrt_min((letter - 65) * 4));
	return (0);
}
