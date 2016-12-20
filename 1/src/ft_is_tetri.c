/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2016/12/21 00:52:51 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

char	*ft_istetri(int fd, int ext)
{
	char			buf[21];

	ft_bzero(buf, 22);
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
		ft_putendl_fd(buf, ext);
		ft_bzero(buf, 22);
	}
	return ("coucou");
}
