/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:36:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/07 12:23:42 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char		*ft_parsing(char *str)
{
	char	tetri_valid[189];
	char	*tmp;
	int		i;

	i = 0;
	ft_bzero(tetri_valid, 190);
	ft_strcpy(tetri_valid, "##..##.\n####\n#...#...#...#\n#...##...#\
	\n#..##..#\n##...##\n##.##\n#...###\n##..#...#\n###...#\n#...#..##\n#.###\
	\n#...#...##\n###.#\n##...#...#\n###..#\n#..##...#\n#..###\n#...##..#");
	if (!((str[4] == 10 && str[9] == 10 && str[14] == 10 && str[19] == 10 &&
		(str[20] == 0 || str[20] == 10))) || (ft_count_occur(str, '#') != 4
		|| ft_count_occur(str, '.') != 12))
		return (NULL);
	while (ft_strchr(str, '\n') != NULL)
		ft_strcpy(ft_strchr(str, '\n'), ft_strchr(str, '\n') + 1);
	while (str[i++])
		if (str[i] == '#' && str[i - 1] == '#')
			if (i / 4 != (i - 1) / 4)
				return (NULL);
	if (ft_strstr(tetri_valid, (tmp = ft_strctrim(str, '.'))) == 0)
		return (NULL);
	ft_strdel(&tmp);
	return (str);
}
