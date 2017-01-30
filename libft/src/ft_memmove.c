/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:40:40 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/18 01:50:11 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Copies n bytes from memory area src to memory area
** dest. The memory areas may overlap: copying takes place as though the bytes
** in src are first copied into a temporary array that does not overlap src or
** dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	if ((tmp = (unsigned char *)ft_memalloc(sizeof(unsigned char) * n)))
	{
		while (i < n)
		{
			tmp[i] = ((unsigned char *)src)[i];
			i++;
		}
		ft_memcpy(dest, tmp, n);
		free(tmp);
		tmp = NULL;
		return (dest);
	}
	return ((void *)src);
}
