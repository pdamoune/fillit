/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:04:44 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/20 01:39:32 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies the character c (an unsigned char) to the first n characters of the
** string pointed to, by the argument str.
*/

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)str;
	while (i < n)
		tmp[i++] = (unsigned char)c;
	return (str);
}
