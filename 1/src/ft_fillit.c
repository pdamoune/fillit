/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:50 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/29 02:32:04 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(char *argv)
{
	int		fd;
	t_list	*tetri;

	fd = open(argv, O_RDONLY);
    if (fd == -1)
		exit(1);
    tetri = ft_istetri(fd);
	// ft_move_tetri(tetri);
	// if (tetri != NULL)
	// 	ft_displaytetri(tetri);
	ft_putendl("");
	close(fd);
}
