/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:18:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:05:06 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compte le nombre d occurence de l int c dans str
*/

int		ft_count_occur(char *str, int c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}
