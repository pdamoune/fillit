/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:14:10 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/21 03:26:16 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends the NUL-terminated string src to the end of dst. It will append at
** most size - strlen(dst) - 1 bytes, NUL-terminating the result.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmp;
	size_t	len;

	tmp = (char *)ft_memchr(dst, '\0', size);
	if (tmp == NULL)
		return (size + ft_strlen(src));
	len = (size_t)(tmp - dst) + ft_strlen(src);
	while ((size_t)(tmp - dst) < size - 1 && *src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (len);
}
