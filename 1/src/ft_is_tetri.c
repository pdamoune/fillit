/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:40:29 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/22 18:04:06 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_istetri(int fd)
{
	char			str[21];
	char			*tmp;


	ft_bzero(str, 22);
	while (read(fd, str, 21) > 0)
	{
		tmp = ft_strdup(str);
		// ft_putendl(tmp);
		// ft_putendl(str);
		tmp = ft_is_good(tmp);
		// 	ft_struc(tmp, str, n)
		//ft_putendl(tmp);
		// ft_putendl("");
	}
	//ft_putendl(tmp);
	if (tmp == 0)
		return (0);
	ft_putstr(ft_conv_bin(tmp, '#', '.'));
	//tmp = ft_conv_bin(tmp, '#', '.');
	return (0);
}
