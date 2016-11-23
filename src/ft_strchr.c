/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:17:07 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/20 01:53:31 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the first occurrence of the character c (an unsigned char) in
** the string pointed to by the argument str.
*/

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
		if (c == '\0' && str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
	}
	return (NULL);
}
