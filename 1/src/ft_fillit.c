/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2016/12/21 00:54:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_fillit(char *argv)
{
	int		fd;
	int		ext;
	// char	*tetri;

	fd = open(argv, O_RDONLY);
	ext = open("extern_file.txt", O_TRUNC | O_RDWR);
    if (fd == -1)
		exit(1);
	ft_istetri(fd, ext);

	// ft_move_tetri(tetri);
	// if (tetri != NULL)
	// 	ft_displaytetri(tetri);
	ft_putendl("");
	close(ext);
	close(fd);
}
