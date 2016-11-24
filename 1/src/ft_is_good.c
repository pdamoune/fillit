/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:36:38 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/24 10:11:15 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_good(char *str)
{
	char	*tetri_valid;
	char	*tmp;

	tetri_valid = ft_strdup("##..##\n####\n#...#...#...#\n#...##...#\
	\n#..##..#\n##...##\n##.##..\n#...###\n##..#...#\n###...#\n#...#..##\n#.###\
	\n#...#...##\n###.#\n##...#...#\n###..#\n#..##...#\n#..###\n#...##..#");
	tmp = ft_strdup(str);
	if (((tmp[4] & tmp[9] & tmp[14] & tmp[19]) == 10)
	&& (tmp[20] == 0 || tmp[20] == 10))
		if (ft_count_occur(tmp, '#') == 4 && ft_count_occur(tmp, '.') == 12)
			while (ft_strchr(tmp, '\n') != NULL)
				ft_memmove(ft_strchr(tmp, '\n'), ft_strchr(tmp, '\n') + 1,
				ft_strlen(tmp));
	if (ft_strstr(tetri_valid, ft_strctrim(tmp, '.')) != 0)
		return (1);
	return (0);
}
