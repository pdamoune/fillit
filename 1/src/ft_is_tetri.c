/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/12 05:51:56 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

char 	*ft_set_tetris(char *buf)
{
	char *tetri;

	tetri = ft_strnew(200);
	ft_memset(tetri, '.', 200);
	ft_strcpy(tetri, buf);
	*ft_strchr(tetri, '\0') = '.';
	tetri[16] = 0;
	return (tetri);
}

int 	ft_is_tetri(int fd, char **tetris, char **lst_tetri)
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
		tetris[letter - 65] = ft_set_tetris(buf);
		lst_tetri[letter - 65] = ft_strdup(tetris[letter - 65]);
		*(ft_strrchr(lst_tetri[letter - 65], letter) + 1) = 0;
		ft_bzero(buf, 22);
		letter++;
	}
	lst_tetri[letter - 65] = ft_strdup(buf);
	tetris[letter - 65] = ft_strdup(buf);
	return (ft_sqrt_min((letter - 65) * 4));
}
