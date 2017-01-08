/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:46:06 by philippe          #+#    #+#             */
/*   Updated: 2016/12/24 19:41:45 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_gnl(const int fd, char *nl, char *next_line, char *line)
{
	char		buf[15];
	int			i;

	i = 0;
	ft_bzero(buf, 15);
	if (next_line[0])
		ft_strcpy(line, next_line);
	while ((i = read(fd, buf, 14)) > 0 )
	{
		buf[i] = 0;
		if (!((nl = ft_strchr(buf, '\n')) || (nl = ft_strchr(next_line, '\n'))))
			line = ft_strcat(line, buf);
		else
		{
			*nl = 0;
			ft_strcat(line, buf);
			ft_strcpy(next_line, nl + 1);
			return (1);
		}
	}
	return (i);
}

int		ft_get_next_line(const int fd, char *line)
{
	static char	next_line[1000] = "";
	char 		*nl;


	if ((nl = ft_strchr(next_line, '\n')))
	{
		*nl = 0;
		ft_strcpy(line, next_line);
		ft_strcpy(next_line, nl + 1);
		return (1);
	}
	if ((ft_gnl(fd, nl, next_line, line)) == 1)
		return (1);
	ft_strchr(next_line, '\0') ? next_line[0] = 0 : 0;
	if (ft_gnl(fd, nl, next_line, line) == 0)
		return(0);
	return (-1);
}
